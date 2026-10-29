// Minimum Operations to Make the Array Increasing
// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Accepted 2025-10-08 | Runtime 8 ms | Memory 19.6 MB

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int temp = nums[i];
                nums[i] = nums[i-1]+1;
                count += nums[i] - temp;
            }
        }

        return count;
    }
};