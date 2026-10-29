// Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Accepted 2025-07-26 | Runtime 0 ms | Memory 41.4 MB

class Solution {
    public boolean check(int[] nums) {
        int count = 0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        if(nums[0]<nums[nums.length-1]){
            count++;
        }
        return count <= 1 ? true : false;
    }
}