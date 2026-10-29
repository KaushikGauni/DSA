// Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/
// Accepted 2026-08-25 | Runtime 7 ms | Memory 12.5 MB

class Solution {
public:

    int recurse(int idx, int k, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = INT_MIN;
        int temp = INT_MIN;
        for(int i=idx;i<min(n,idx+k);i++){
            temp = max(temp,arr[i]);
            ans = max(ans, temp*(i-idx+1) + recurse(i+1,k,arr,dp));
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return recurse(0,k,arr,dp);
    }
};