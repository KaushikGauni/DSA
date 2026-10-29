// Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Accepted 2022-09-18 | Runtime 0 ms | Memory 43.3 MB

class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(target<nums[mid]){
                end = mid - 1;
            }
            else if(target>nums[mid]){
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
        
        return start;
    }
}