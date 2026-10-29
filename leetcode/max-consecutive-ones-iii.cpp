// Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/
// Accepted 2026-08-12 | Runtime 0 ms | Memory 69.7 MB

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeroes = 0, maxRes = 0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==0){
                zeroes++;
            }

            if(zeroes > k){
                if(nums[left]==0){
                    zeroes--;
                }
                left++;
            }

            maxRes = max(maxRes, right-left+1);
        }

        return maxRes;
    }
};