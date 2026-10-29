// Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/
// Accepted 2026-08-18 | Runtime 0 ms | Memory 16.9 MB

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr(nums.size()*2);
        for(int i=0;i<nums.size();i++){
            arr[i] = nums[i];
            arr[i+nums.size()] = nums[i];
        }

        return arr;
    }
};