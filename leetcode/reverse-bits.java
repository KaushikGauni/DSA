// Reverse Bits
// https://leetcode.com/problems/reverse-bits/
// Accepted 2023-12-19 | Runtime 1 ms | Memory 40.3 MB

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for(int i=0;i<32;i++){
            res<<=1;
            if((n&1)==1){
                res+=1;
            }
            n>>=1;
        }
        return res;
    }
}