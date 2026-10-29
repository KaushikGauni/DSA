// Reverse Integer
// https://leetcode.com/problems/reverse-integer/
// Accepted 2025-07-29 | Runtime 0 ms | Memory 40.8 MB

class Solution {
    public int reverse(int x) {
        long res = 0;
        while(x!=0){
            res = res*10 + (x%10);
            x = x/10;
        }
        if(res<Integer.MIN_VALUE || res>Integer.MAX_VALUE){
            return 0;
        }
        return (int)res;
    }
}