// First n Fibonacci using Recursion (Basic)
// https://www.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
// Correct 2023-07-23 21:09:42 | Java



//User function Template for Java


class Solution
{
    //Function to return list containing first n fibonacci numbers.
    public static long[] printFibb(int n) 
    {
        //Your code here
        long dp[]=new long[n];
        Arrays.fill(dp,-1);
        if(n==1){
            long[] dp1 = {1};
            return dp1;
        }
        dp[0]= 1;
        dp[1]= 1;
        
        for(int i=2; i<n; i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp;
    }
}