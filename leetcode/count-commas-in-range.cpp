// Count Commas in Range
// https://leetcode.com/problems/count-commas-in-range/
// Accepted 2026-09-09 | Runtime 0 ms | Memory 8.6 MB

class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        return (n-999);
    }
};