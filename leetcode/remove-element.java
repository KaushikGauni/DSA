// Remove Element
// https://leetcode.com/problems/remove-element/
// Accepted 2023-06-24 | Runtime 0 ms | Memory 41 MB

class Solution {
    public int removeElement(int[] nums, int val) {
        int[] temp = new int[nums.length];
        int i = 0;
        for(int j=0;j<nums.length;j++){
            if(nums[j]==val){
                continue;
            }
            else{
                temp[i++] = nums[j];
            }
        }
        for(int j=0;j<nums.length;j++){
            nums[j] = temp[j];
        }
        return i;
    }
}