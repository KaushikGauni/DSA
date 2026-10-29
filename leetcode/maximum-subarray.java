// Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// Accepted 2025-08-03 | Runtime 1 ms | Memory 56.9 MB

class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int curr = nums[0];
        for(int i=1;i<nums.length;i++){
            curr = Math.max(curr+nums[i], nums[i]);
            max = Math.max(max,curr);
        }

        return max;
    }
}