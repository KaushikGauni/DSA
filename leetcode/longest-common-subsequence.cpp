// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/
// Accepted 2026-09-23 | Runtime 49 ms | Memory 27.6 MB

class Solution {
public:

    int recurse(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j] = 1 + recurse(i+1,j+1,text1,text2,dp);
        }
        int x = recurse(i+1,j,text1,text2,dp);
        int y = recurse(i,j+1,text1,text2,dp);

        return dp[i][j] = max(x,y);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return recurse(0,0,text1,text2,dp);
    }
};