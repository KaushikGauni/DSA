// Burst Balloons
// https://leetcode.com/problems/burst-balloons/
// Accepted 2026-08-25 | Runtime 211 ms | Memory 13.9 MB

class Solution {
public:

    int recurse(int i, int j, vector<vector<int>> &dp, vector<int> &nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            ans = max(ans, nums[i-1]*nums[k]*nums[j+1] + recurse(i,k-1,dp,nums) + recurse(k+1,j,dp,nums));
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recurse(1,n-2,dp,nums);
    }
};