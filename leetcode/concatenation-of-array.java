// Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/
// Accepted 2022-08-17 | Runtime 1 ms | Memory 49.8 MB

class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2*n];
        for(int i=0;i<n;i++){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
    }
}