// Reverse Bits
// https://leetcode.com/problems/reverse-bits/
// Accepted 2025-12-09 | Runtime 0 ms | Memory 8.1 MB

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i=0;i<32;i++){
            res = res << 1;
            res = res | (n&1);
            n = n >> 1;
        }
        return res;
    }
};