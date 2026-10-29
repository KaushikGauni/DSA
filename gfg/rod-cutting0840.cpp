// Rod Cutting (Medium)
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Correct 2026-09-27 13:45:42 | C++

class Solution {
  public:
  
    int recurse(int i, int n, vector<int> &price, vector<vector<int>> &dp){
        if(i<0 || n==0){
            return 0;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int notcut = recurse(i-1,n,price,dp);
        int cut = 0;
        if((i+1)<=n){
            cut =  price[i] + recurse(i,n-i-1,price,dp);
        }
        return dp[i][n] = max(cut,notcut);
    }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recurse(n-1,n,price,dp);
    }
};