// House Robber
// https://leetcode.com/problems/house-robber/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 10.8 MB

class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return nums[0];
        }

        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+1],nums[i]+dp[i+2]);
        }

        return dp[0];
    }
};