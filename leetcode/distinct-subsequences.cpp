// Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/
// Accepted 2026-07-24 | Runtime 30 ms | Memory 26.9 MB

class Solution {
public:

    int recur(int n, int m, string& s, string& t,vector<vector<int>> &dp){
        if(m<0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n]==t[m]){
            return dp[n][m] = recur(n-1,m-1,s,t,dp) + recur(n-1,m,s,t,dp);
        }
        return dp[n][m] = recur(n-1,m,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recur(n-1,m-1,s,t,dp);
    }
};