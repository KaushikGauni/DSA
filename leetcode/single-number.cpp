// Single Number
// https://leetcode.com/problems/single-number/
// Accepted 2026-07-28 | Runtime 0 ms | Memory 20.5 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i : nums){
            res ^= i;
        }
        return res;
    }
};