// Optimal Strategy for Game (Medium)
// https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
// Correct 2026-10-05 17:34:02 | C++

class Solution {
  public:
  
    int recurse(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==j) return dp[i][j] = arr[i];
        
        
        int left = arr[i] + min(recurse(i+2,j,arr,dp), recurse(i+1,j-1,arr,dp));
        int right = arr[j] + min(recurse(i+1,j-1,arr,dp), recurse(i,j-2,arr,dp));
        
        return dp[i][j] = max(left,right);
    }
  
    int maximumAmount(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return recurse(0,arr.size()-1,arr,dp);
    }
};