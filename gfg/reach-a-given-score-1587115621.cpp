// Count Ways with 3, 5 and 10 (Easy)
// https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// Correct 2026-09-23 10:24:01 | C++


class Solution {
  public:
  
    int count(int n, int i, vector<int> &steps, vector<vector<int>> &dp){
        if(n==0){
            return 1;
        }
        if(n<0 || i>=steps.size()){
            return 0;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        return dp[n][i] = count(n-steps[i],i,steps,dp) + count(n,i+1,steps,dp);
    }
  
    int countWays(int n) {
        //  code here
        vector<int> steps = {3,5,10};
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return count(n,0,steps,dp);
        
    }
};