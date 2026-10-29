// DI String Match
// https://leetcode.com/problems/di-string-match/
// Accepted 2025-10-08 | Runtime 0 ms | Memory 11.9 MB

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0;
        int j = s.length();
        vector<int> res;
        for(char c : s){
            if(c=='I'){
                res.push_back(i);
                i++;
            }
            else if(c=='D'){
                res.push_back(j);
                j--;
            }
        }
        res.push_back(i);
        return res;
    }
};