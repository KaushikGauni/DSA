// Missing Number
// https://leetcode.com/problems/missing-number/
// Accepted 2025-08-03 | Runtime 0 ms | Memory 45.5 MB

class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int n = nums.length + 1;
        int act = n*(n-1)/2;
        return act-sum;
    }
}