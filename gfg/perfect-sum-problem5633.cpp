// Count Subsets with Sum (Medium)
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Correct 2026-09-27 13:54:11 | C++

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> dp(target+1,0);
        dp[0] = 1;
        
        for(int i : arr){
            for(int j = target;j>=i;j--){
                dp[j] += dp[j-i];
            }
        }
        
        return dp[target];
    }
};