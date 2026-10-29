// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Accepted 2025-08-03 | Runtime 3 ms | Memory 56.1 MB

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        left[0] = 1;
        for(int i=1;i<nums.length;i++){
            left[i] = left[i-1] * nums[i-1];
        }
        int[] right = new int[nums.length];
        int[] res = new int[nums.length];
        right[nums.length-1] = 1;
        for(int i=nums.length-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i=0;i<nums.length;i++){
            res[i] = left[i] * right[i];
        }
        return res;
    }
}