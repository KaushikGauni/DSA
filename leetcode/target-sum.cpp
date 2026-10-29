// Target Sum
// https://leetcode.com/problems/target-sum/
// Accepted 2026-07-23 | Runtime 253 ms | Memory 61.2 MB

class Solution {
public:

    int recurse(vector<int>& nums, int target, int n, map<pair<int,int>,int> &dp){
        if(n<0){
            return target==0;
        }
        if(dp.count({n,target})){
            return dp[{n,target}];
        }
        int positive = nums[n] + recurse(nums,target-nums[n],n-1,dp);
        int negative = -nums[n] + recurse(nums,target+nums[n],n-1,dp);

        return dp[{n,target}] = negative + positive;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int> dp;
        return recurse(nums,target,n-1,dp); 
    }
};