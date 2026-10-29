// Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Accepted 2023-06-24 | Runtime 0 ms | Memory 43.9 MB

class Solution {
    public int removeDuplicates(int[] nums) {
        int i =0;
        for(int n : nums){
            if(i<2 || n>nums[i-2]){
                nums[i++] = n;
            }
        }
        return i;
    }
}