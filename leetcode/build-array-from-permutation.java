// Build Array from Permutation
// https://leetcode.com/problems/build-array-from-permutation/
// Accepted 2022-08-17 | Runtime 1 ms | Memory 53.4 MB

class Solution {
    public int[] buildArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            ans[i] = nums[nums[i]];
        }
        
        return ans;
    }
}