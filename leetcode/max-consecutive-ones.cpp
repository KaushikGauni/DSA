// Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
// Accepted 2026-08-12 | Runtime 0 ms | Memory 50.1 MB

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int right = 0, res = 0, maxRes = 0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==1){
                res++;
            }
            else{
                res = 0;
            }
            maxRes = max(maxRes, res);
        }

        return maxRes;
    }
};