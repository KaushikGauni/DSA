// Binary Digit Score
// https://leetcode.com/problems/binary-digit-score/
// Accepted 2026-10-29 | Runtime 0 ms | Memory 8.5 MB

class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = __builtin_popcount(a);
        int s2 = __builtin_popcount(b);
        if (s1 >= s2) return s1 * s2;
        return s2 / s1;
    }
};