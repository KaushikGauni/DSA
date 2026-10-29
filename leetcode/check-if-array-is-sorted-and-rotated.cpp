// Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Accepted 2026-06-15 | Runtime 0 ms | Memory 11.1 MB

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
            }
        }

        if(nums[0]<nums[nums.size()-1]){
            count++;
        }
        return count <= 1 ? true : false;
    }
};