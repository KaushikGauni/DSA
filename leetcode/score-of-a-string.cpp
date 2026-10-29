// Score of a String
// https://leetcode.com/problems/score-of-a-string/
// Accepted 2025-11-03 | Runtime 0 ms | Memory 9 MB

class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for(int i=1;i<s.size();i++){
            res += abs(s[i]-s[i-1]);
        }
        return res;
    }
};