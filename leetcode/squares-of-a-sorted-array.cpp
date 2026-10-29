// Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/
// Accepted 2025-11-28 | Runtime 2 ms | Memory 30.4 MB

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &i : nums){
            i = i*i;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};