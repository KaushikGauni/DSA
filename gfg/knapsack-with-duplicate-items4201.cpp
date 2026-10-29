// Knapsack with Duplicate Items (Medium)
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Correct 2026-10-27 18:13:29 | C++

class Solution {
  public:
    
    int recurse(int i, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>> &dp){
        if(capacity == 0 || i >= val.size()){
            return 0;
        }
        if(dp[i][capacity] != -1) return dp[i][capacity];
        int notpick = recurse(i+1,val,wt,capacity,dp);
        int pick = 0;
        if(wt[i] <= capacity){
            pick = val[i] + recurse(i,val,wt,capacity-wt[i],dp);
        }
        
        return dp[i][capacity] = max(pick,notpick);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(val.size(), vector<int>(capacity+1,-1));
        return recurse(0,val,wt,capacity,dp);
    }
};