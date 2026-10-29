// 0 - 1 Knapsack Problem (Medium)
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Correct 2026-10-26 14:58:51 | C++

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W+1, 0);
        for(int i=0;i<(int)val.size();i++){
            for(int capacity = W;capacity >= wt[i]; --capacity){
                dp[capacity] = max(dp[capacity], val[i] + dp[capacity - wt[i]]);
            }
        }
        
        return dp[W];
    }
};