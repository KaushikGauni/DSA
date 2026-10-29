// Power of Two
// https://leetcode.com/problems/power-of-two/
// Accepted 2026-06-23 | Runtime 0 ms | Memory 7.9 MB

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        if((n&(n-1))==0){
            return true;
        }
        return false;
    }
};