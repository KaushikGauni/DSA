// Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// Accepted 2026-09-18 | Runtime 0 ms | Memory 71.9 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0],maxSum = nums[0];
        for(int i=1;i<nums.size();i++){
            curr = max(nums[i], curr + nums[i]);
            maxSum = max(maxSum, curr);
        }

        return maxSum;
    }
};