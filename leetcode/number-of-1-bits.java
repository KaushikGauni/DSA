// Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
// Accepted 2025-08-03 | Runtime 0 ms | Memory 40.9 MB

class Solution {
    public int hammingWeight(int n) {
        int hamming_weight = 0;
        while(n!=0){
            if((n&1)==1){
                hamming_weight++;
            }
            n = n >> 1;
        }

        return hamming_weight;
    }
}