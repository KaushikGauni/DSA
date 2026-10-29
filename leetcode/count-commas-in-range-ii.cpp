// Count Commas in Range II
// https://leetcode.com/problems/count-commas-in-range-ii/
// Accepted 2026-09-09 | Runtime 0 ms | Memory 9.2 MB

class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long temp = 1000;
        while(temp <= n){
            res += n - temp + 1;
            temp *= 1000;
        }

        return res;
    }
};