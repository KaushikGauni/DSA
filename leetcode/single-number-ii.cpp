// Single Number II
// https://leetcode.com/problems/single-number-ii/
// Accepted 2026-08-07 | Runtime 0 ms | Memory 13.4 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i : nums){
            ones = (ones ^ i) & ~twos;
            twos = (twos ^ i) & ~ones;
        }
        return ones;
    }
};