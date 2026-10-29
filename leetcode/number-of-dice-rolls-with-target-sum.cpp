// Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Accepted 2026-07-18 | Runtime 33 ms | Memory 13.2 MB

class Solution {
public:
    const int MOD = 1000000007;
    int help(int n, int k, int target, vector<vector<int>> &dp){
        if(n==0){
            return target==0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                ans = (ans + help(n-1,k,target-i,dp)) % MOD;
            }
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int l=1;l<=k;l++){
                    if(l<=j){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
        // return help(n,k,target,dp);
    }
};