// Longest Repeating Subsequence (Medium)
// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Correct 2026-10-06 11:31:02 | C++

class Solution {
  public:
    
    int recurse(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>=s.size() || j>=s.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j] && i!=j){
            return dp[i][j] = 1 + recurse(i+1,j+1,s,dp);
        }
        
        int x = recurse(i+1,j,s,dp);
        int y = recurse(i,j+1,s,dp);
        
        return dp[i][j] = max(x,y);
    }
  
    int longestRepSubseq(string &s) {
        // Code here
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        return recurse(0,0,s,dp);
    }
};