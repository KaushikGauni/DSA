// Longest Palindromic Subsequence (Medium)
// https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
// Correct 2026-10-03 18:38:50 | C++

class Solution {
  public:
  
    int recurse(int i, int j, string &s,vector<vector<int>> &dp){
        if(i>j || i>=s.size() || j<0) return 0;
        
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]) return dp[i][j] = 2 + recurse(i+1,j-1,s,dp);
        
        int x = recurse(i+1,j,s,dp);
        int y = recurse(i,j-1,s,dp);
        
        return dp[i][j] = max({x,y});
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max({dp[i+1][j], dp[i][j-1]});
                }
            }
        }
        
        return dp[0][n-1];
    }
};