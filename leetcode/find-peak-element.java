// Find Peak Element
// https://leetcode.com/problems/find-peak-element/
// Accepted 2023-07-24 | Runtime 0 ms | Memory 41.6 MB

class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, mid = 0, r = nums.length-1;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid]<nums[mid+1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
}