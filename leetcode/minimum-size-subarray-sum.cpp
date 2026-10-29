// Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// Accepted 2026-08-03 | Runtime 0 ms | Memory 42 MB

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        for(right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                if(minLen > right-left+1){
                    minLen = right-left+1;
                }
                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};