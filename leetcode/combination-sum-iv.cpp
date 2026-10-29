// Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 9.3 MB

class Solution {
public:

    int recurse(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0){
            return 1;
        }

        if(dp[target]!=-1){
            return dp[target];
        }

        int ans = 0;

        for(int i : nums){
            if(i <= target){
                ans += recurse(nums,target-i,dp);
            }
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return recurse(nums,target,dp);
    }
};