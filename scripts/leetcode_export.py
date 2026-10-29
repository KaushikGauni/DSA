"""Download all accepted LeetCode submissions (latest per problem per language).

Cookies are read from cookies_leetcode.txt next to this script:
    LEETCODE_SESSION=...
    csrftoken=...
"""
import os, sys, time, datetime, requests

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "..", "leetcode")
EXT = {"python3": "py", "python": "py", "pythondata": "py", "cpp": "cpp", "java": "java",
       "javascript": "js", "typescript": "ts", "c": "c", "csharp": "cs", "golang": "go",
       "kotlin": "kt", "swift": "swift", "rust": "rs", "ruby": "rb", "scala": "scala",
       "php": "php", "mysql": "sql", "mssql": "sql", "oraclesql": "sql", "postgresql": "sql",
       "bash": "sh", "dart": "dart", "elixir": "ex", "erlang": "erl", "racket": "rkt"}
COMMENT = {"py": "#", "rb": "#", "sh": "#", "ex": "#", "sql": "--", "erl": "%", "rkt": ";"}


def load_cookies():
    path = os.path.join(HERE, "cookies_leetcode.txt")
    cookies = {}
    for line in open(path, encoding="utf-8"):
        if "=" in line:
            k, v = line.strip().split("=", 1)
            cookies[k.strip()] = v.strip().strip('"')
    if not cookies.get("LEETCODE_SESSION") or not cookies.get("csrftoken"):
        sys.exit("cookies_leetcode.txt needs LEETCODE_SESSION and csrftoken")
    return cookies


LIST_Q = """query($offset:Int!,$limit:Int!,$lastKey:String){ submissionList(offset:$offset,limit:$limit,lastKey:$lastKey){
  lastKey hasNext submissions{ id title titleSlug statusDisplay lang timestamp } } }"""
DETAIL_Q = """query($id:Int!){ submissionDetails(submissionId:$id){ code runtimeDisplay memoryDisplay } }"""


def gql(s, query, variables):
    # The old /api/submissions/ REST endpoint sits behind a Cloudflare challenge; GraphQL does not.
    for attempt in range(6):
        r = s.post("https://leetcode.com/graphql/", json={"query": query, "variables": variables})
        if r.status_code == 200 and "errors" not in r.json():
            return r.json()["data"]
        if r.status_code in (200, 403, 429, 502, 503):
            time.sleep(5 * (attempt + 1))
            continue
        r.raise_for_status()
    sys.exit(f"Gave up on GraphQL (last status {r.status_code}: {r.text[:200]}). Cookies may be expired.")


def main():
    cookies = load_cookies()
    s = requests.Session()
    s.cookies.update(cookies)
    s.headers.update({"Referer": "https://leetcode.com/", "Origin": "https://leetcode.com",
                      "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/141.0 Safari/537.36",
                      "x-csrftoken": cookies["csrftoken"], "Content-Type": "application/json"})
    os.makedirs(OUT, exist_ok=True)

    latest, total = {}, 0
    offset, lastkey = 0, None
    while True:
        data = gql(s, LIST_Q, {"offset": offset, "limit": 20, "lastKey": lastkey})["submissionList"]
        for sub in data["submissions"]:  # newest first
            total += 1
            ext = EXT.get(sub["lang"], "txt")
            if sub["statusDisplay"] == "Accepted":
                latest.setdefault((sub["titleSlug"], ext), sub)
        print(f"listed {total} submissions, {len(latest)} accepted solutions", flush=True)
        if not data["hasNext"] or not data["submissions"]:
            break
        offset += 20
        lastkey = data["lastKey"]
        time.sleep(1)

    for i, ((slug, ext), sub) in enumerate(latest.items(), 1):
        d = gql(s, DETAIL_Q, {"id": int(sub["id"])})["submissionDetails"]
        c = COMMENT.get(ext, "//")
        when = datetime.datetime.fromtimestamp(int(sub["timestamp"])).strftime("%Y-%m-%d")
        header = (f"{c} {sub['title']}\n{c} https://leetcode.com/problems/{slug}/\n"
                  f"{c} Accepted {when} | Runtime {d['runtimeDisplay']} | Memory {d['memoryDisplay']}\n\n")
        with open(os.path.join(OUT, f"{slug}.{ext}"), "w", encoding="utf-8") as f:
            f.write(header + d["code"])
        if i % 25 == 0:
            print(f"downloaded {i}/{len(latest)}", flush=True)
        time.sleep(0.7)
    print(f"Done: {len(latest)} files in {os.path.abspath(OUT)}")


if __name__ == "__main__":
    main()
