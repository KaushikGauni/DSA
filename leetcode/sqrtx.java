// Sqrt(x)
// https://leetcode.com/problems/sqrtx/
// Accepted 2023-06-27 | Runtime 1 ms | Memory 39.4 MB

class Solution {
    public int mySqrt(int x) {
        long r = x;
        while(r*r>x){
            r = (r+x/r)/2;
        }
        return (int)r;
    }
}