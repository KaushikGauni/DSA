// Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/
// Accepted 2026-09-28 | Runtime 0 ms | Memory 32.6 MB

class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0, right = 0, count = 0;
        int sum = 0;
        for(right = 0;right<nums.size();right++){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};