// Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// Accepted 2025-07-26 | Runtime 1 ms | Memory 45.7 MB

class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                nums[j++] = nums[i];
            }
        }
        for(int k=j;k<nums.length;k++){
            nums[k] = 0;
        }
    }
}