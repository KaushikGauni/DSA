// Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// Accepted 2026-06-18 | Runtime 0 ms | Memory 8.3 MB

class Solution {
public:
    int findfib(vector<int> &fibs, int n){
        if(fibs[n]!=-1){
            return fibs[n];
        }
        return fibs[n] = findfib(fibs,n-1) + findfib(fibs,n-2);
    }
    int fib(int n) {
        if(n==0) return 0;
        vector<int> fibs(n+1,-1);
        fibs[0] = 0;
        fibs[1] = 1;
        return findfib(fibs,n);
    }
};