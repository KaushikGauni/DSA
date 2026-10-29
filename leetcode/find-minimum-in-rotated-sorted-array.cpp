// Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Accepted 2026-09-20 | Runtime 0 ms | Memory 14.2 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return nums[start];
    }
};