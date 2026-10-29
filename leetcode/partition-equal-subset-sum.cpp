// Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// Accepted 2026-07-22 | Runtime 96 ms | Memory 13.3 MB

class Solution {
public:

    bool cancan(vector<vector<int>> &dp, vector<int>& nums, int n, int sum){
        if(sum==0){
            return true;
        }
        if(n<0){
            return false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        bool notpick = cancan(dp,nums,n-1,sum);
        bool pick = false;
        if(nums[n]<=sum){
            pick = cancan(dp,nums,n-1,sum-nums[n]);
        }
        return dp[n][sum] = notpick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum / 2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=nums[i];j--){
                bool notpick = dp[j];
                bool pick = dp[j-nums[i]];
                dp[j] = pick || notpick;
            }
        }
        return dp[sum];
    }
};