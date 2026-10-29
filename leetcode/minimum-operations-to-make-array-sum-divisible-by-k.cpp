// Minimum Operations to Make Array Sum Divisible by K
// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Accepted 2026-08-20 | Runtime 0 ms | Memory 45.4 MB

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};