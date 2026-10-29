// Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/
// Accepted 2025-12-10 | Runtime 0 ms | Memory 7.7 MB

class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while(b){
            c = (a&b);
            a = a ^ b;
            b = c<<1;
        }
        return a;
    }
};