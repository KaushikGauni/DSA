// Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// Accepted 2025-08-02 | Runtime 0 ms | Memory 40.2 MB

class Solution {
    
    static int[] dp = new int[40];
    public int fib(int n) {
        for(int i=0;i<n;i++){
            dp[i] = 0;
        }
        dp[0] = 0;
        dp[1] = 1;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        dp[n] = fib(n-1) + fib(n-2);

        return dp[n];
    }
}