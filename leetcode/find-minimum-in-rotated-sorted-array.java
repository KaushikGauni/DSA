// Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Accepted 2025-08-05 | Runtime 0 ms | Memory 42.3 MB

class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length-1;
        while(start<end){
            int mid = (start+end)/2;
            if(nums[mid]>nums[end]){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }

        return nums[start];
    }
}