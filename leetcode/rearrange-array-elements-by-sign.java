// Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Accepted 2025-07-26 | Runtime 6 ms | Memory 81.8 MB

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int i=0,j=0,k=0;
        int[] res = new int[nums.length];
        while(k<nums.length){
                while(nums[i]<0){
                    i++;
                }
                while(nums[j]>0){
                    j++;
                }
                res[k] = nums[i];
                k++;
                res[k] = nums[j];
                k++;
                i++;
                j++;
        }

        return res;
    }
}