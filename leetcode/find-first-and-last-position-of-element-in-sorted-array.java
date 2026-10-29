// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Accepted 2022-09-17 | Runtime 11 ms | Memory 48.4 MB

class Solution {
    public int[] searchRange(int[] nums, int target) {
        List<Integer> l = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            l.add(nums[i]);
        }
        int[] a = {-1,-1};
        a[0] = l.indexOf(target);
        a[1] = l.lastIndexOf(target);
        return a;
    }
}