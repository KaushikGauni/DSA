"""Download all correct GeeksforGeeks submissions (latest per problem per language).

The raw Cookie header of a logged-in practiceapi.geeksforgeeks.org request goes in
cookies_gfg.txt next to this script.
"""
import os, sys, time, requests

HANDLE = "gaunikaushik"
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "..", "gfg")
API = "https://practiceapi.geeksforgeeks.org/api/latest/"
EXT = {"cpp": "cpp", "c": "c", "java": "java", "python3": "py", "python": "py",
       "javascript": "js", "csharp": "cs", "kotlin": "kt", "go": "go"}
COMMENT = {"py": "#"}


def get(s, url, **kw):
    for attempt in range(6):
        r = s.get(url, **kw)
        if r.status_code == 200:
            return r.json()
        if r.status_code == 403 and "Session" in r.text:
            sys.exit("GFG session expired: refresh cookies_gfg.txt")
        if r.status_code == 403 and "access" in r.text:
            return None  # problem locked behind a course/premium now
        if r.status_code in (403, 429, 502, 503, 504):
            time.sleep(5 * (attempt + 1))
            continue
        r.raise_for_status()
    sys.exit(f"Gave up on {url} (last status {r.status_code})")


def main():
    cookie = open(os.path.join(HERE, "cookies_gfg.txt"), encoding="utf-8").read().strip()
    if not cookie:
        sys.exit("cookies_gfg.txt is empty")
    s = requests.Session()
    s.headers.update({"Cookie": cookie, "Origin": "https://www.geeksforgeeks.org",
                      "Referer": "https://www.geeksforgeeks.org/",
                      "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/152.0 Safari/537.36"})
    os.makedirs(OUT, exist_ok=True)

    r = s.post("https://practiceapi.geeksforgeeks.org/api/v1/user/problems/submissions/",
               json={"handle": HANDLE, "requestType": "", "year": "", "month": ""})
    r.raise_for_status()
    solved = [(level, p) for level, probs in r.json()["result"].items() for p in probs.values()]
    print(f"{len(solved)} solved problems", flush=True)

    done = {os.path.splitext(f)[0] for f in os.listdir(OUT)}
    saved, missing, locked = 0, [], []
    for i, (level, p) in enumerate(solved, 1):
        if p["slug"] in done:  # resume: already downloaded on an earlier run
            continue
        data = get(s, f"{API}problems/{p['slug']}/submissions/user/")
        if data is None:
            locked.append(p["slug"])
            continue
        subs = data["results"]["submissions"]
        latest = {}
        for sub in sorted(subs, key=lambda x: x["subtime"], reverse=True):
            if sub.get("exec_status_text") == "Correct":
                latest.setdefault(sub["lang"], sub)
        if not latest:
            missing.append(p["slug"])
        for lang, sub in latest.items():
            d = get(s, f"{API}problems/submissions/{sub['submission_id']}/")
            if d is None:
                locked.append(p["slug"])
                continue
            code = d.get("user_code") or d.get("code") or ""
            ext = EXT.get(lang, "txt")
            c = COMMENT.get(ext, "//")
            header = (f"{c} {p['pname']} ({level})\n{c} https://www.geeksforgeeks.org/problems/{p['slug']}/1\n"
                      f"{c} Correct {sub['subtime']} | {sub.get('lang_display_name', lang)}\n\n")
            with open(os.path.join(OUT, f"{p['slug']}.{ext}"), "w", encoding="utf-8") as f:
                f.write(header + code)
            saved += 1
            time.sleep(0.5)
        if i % 25 == 0:
            print(f"processed {i}/{len(solved)} problems, {saved} files", flush=True)
        time.sleep(0.5)
    print(f"Done: {saved} files in {os.path.abspath(OUT)}")
    if missing:
        print(f"No correct submission found for {len(missing)}: {', '.join(missing)}")
    if locked:
        print(f"No access (locked) for {len(locked)}: {', '.join(locked)}")


if __name__ == "__main__":
    main()
