// Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
// Accepted 2026-07-28 | Runtime 0 ms | Memory 8.2 MB

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n>0){
            if(n&1==1){
                count++;
            }
            n = n >> 1;
        }

        return count;
    }
};