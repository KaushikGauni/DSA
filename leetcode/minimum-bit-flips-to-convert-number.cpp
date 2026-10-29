// Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Accepted 2026-06-23 | Runtime 2 ms | Memory 8.1 MB

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;
        while(x!=0){
            if(x&1) count++;
            x >>= 1;
        }

        return count;
    }
};