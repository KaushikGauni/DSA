// Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/
// Accepted 2026-07-24 | Runtime 31 ms | Memory 9.9 MB

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp(m+1,false);
        dp[0] = true;
        for(int j=1;j<=m;j++){
            dp[j] = dp[j-1] && p[j-1]=='*';
        }
        for(int i=1;i<=n;i++){
            bool prev = dp[0];
            dp[0] = false;
            for(int j=1;j<=m;j++){
                bool temp = dp[j];
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[j] = prev;
                }
                else if(p[j-1]=='*'){
                    dp[j] = dp[j] || dp[j-1];
                }
                else{
                    dp[j] = false;
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};