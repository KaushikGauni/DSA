// Group Anagrams
// https://leetcode.com/problems/group-anagrams/
// Accepted 2026-09-22 | Runtime 16 ms | Memory 26.3 MB

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        for(string s : strs){
            string t = s;
            sort(t.begin(), t.end());
            hm[t].push_back(s);
        }

        vector<vector<string>> res;
        for(auto st : hm){
            res.push_back(st.second);
        }

        return res;

    }
};