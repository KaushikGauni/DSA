// Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Accepted 2026-08-01 | Runtime 0 ms | Memory 113.8 MB

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left =0, right =0, sum = 0;
        double avg = -1e9;
        for(right=0;right<nums.size();right++){
            sum += nums[right];
            while(right-left+1>k){
                sum -= nums[left];
                left++;
            }
            if(right-left+1==k)
            avg = max(avg, (double)sum/(right-left+1));
        }

        return avg;
    }
};