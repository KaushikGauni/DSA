// Rotate Array
// https://leetcode.com/problems/rotate-array/
// Accepted 2026-06-16 | Runtime 0 ms | Memory 29.5 MB

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // if(nums.size()==1) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+(k%nums.size()));
        reverse(nums.begin()+(k%nums.size()), nums.end());
    }
};