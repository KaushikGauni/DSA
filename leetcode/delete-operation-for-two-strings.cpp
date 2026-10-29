// Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/
// Accepted 2026-07-24 | Runtime 14 ms | Memory 16.8 MB

class Solution {
public:

    int recurse(int n, int m, string &word1, string &word2, vector<vector<int>> &dp){
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n]==word2[m]){
            return 1 + recurse(n-1,m-1,word1,word2,dp);
        }
        int x = recurse(n-1,m,word1,word2,dp);
        int y = recurse(n,m-1,word1,word2,dp);
        return dp[n][m] = max(x,y);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int res = recurse(n-1,m-1,word1,word2,dp);
        return (m-res) + (n-res);
    }
};