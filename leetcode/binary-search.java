// Binary Search
// https://leetcode.com/problems/binary-search/
// Accepted 2025-07-29 | Runtime 0 ms | Memory 45.6 MB

class Solution {
    public int search(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]<target){
                start = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
}