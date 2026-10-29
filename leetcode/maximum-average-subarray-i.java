// Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Accepted 2023-06-27 | Runtime 3 ms | Memory 54.3 MB

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int max = 0;
        for(int i=0;i<k;i++){
            max += nums[i];
        }
        int sum = max;
        for(int i=k;i<nums.length;i++){
            sum = sum + nums[i] - nums[i-k];
            max = Math.max(sum,max);
        }
        return (double)max/k;
    }
}