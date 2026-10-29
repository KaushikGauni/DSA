// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// Accepted 2025-08-15 | Runtime 0 ms | Memory 40.2 MB

class Solution {
    public int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int res = 0;
        int a = 1, b = 2;
        for(int i=3;i<=n;i++){
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
}