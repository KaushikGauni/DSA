// Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Accepted 2025-07-30 | Runtime 0 ms | Memory 40.2 MB

class Solution {
    public int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;
        while(x!=0){
            if((x&1)==1){
                count++;
            }
            x = x>>1;
        }

        return count;
    }
}