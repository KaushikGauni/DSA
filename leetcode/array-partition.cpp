// Array Partition
// https://leetcode.com/problems/array-partition/
// Accepted 2025-10-06 | Runtime 15 ms | Memory 32.2 MB

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=nums.size()-2;i>=0;i-=2){
            sum += nums[i];
        }

        return sum;
    }
};