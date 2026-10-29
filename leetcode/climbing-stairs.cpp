// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 7.9 MB

class Solution {
public:

    // int recurse(int n, vector<int>&dp){
    //     if(n<=2){
    //         return n;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n] = recurse(n-1,dp) + recurse(n-2,dp);
    // }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return recurse(n,dp);
        if(n <= 2){
            return n;
        }

        int prev1 = 1, prev2 = 2;

        for(int i = 3;i <= n;i++){
            int temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }

        return prev2;
    }
};