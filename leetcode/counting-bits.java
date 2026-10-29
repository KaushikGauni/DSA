// Counting Bits
// https://leetcode.com/problems/counting-bits/
// Accepted 2025-08-03 | Runtime 3 ms | Memory 46.6 MB

class Solution {

    public int count(int n){
        int count = 0;
        while(n!=0){
            count += n&1;
            n = n>>1;
        }
        return count;
    }
    public int[] countBits(int n) {
        int res[] = new int[n+1];
        for(int i=0;i<=n;i++){
            res[i] = count(i);
        }
        return res;
    }
}