// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Accepted 2025-01-20 | Runtime 5 ms | Memory 45.3 MB

class Solution {
    public int removeDuplicates(int[] nums) {
        TreeSet<Integer> hs = new TreeSet<Integer>();
        for(int i : nums){
                hs.add(i);
        }
        int k = hs.size();
        for(int i=0;i<k;i++){
            nums[i] = hs.pollFirst();
        }

        return k;
    }
}