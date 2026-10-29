// Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
// Accepted 2025-08-05 | Runtime 1 ms | Memory 44.6 MB

class Solution {
    public int maxProduct(int[] nums) {
        int prefix = 1, suffix = 1;
        int res = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[nums.length-i-1];
            res = Math.max(res, Math.max(prefix, suffix));
        }

        return res;
    }
}