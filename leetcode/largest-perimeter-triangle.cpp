// Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/
// Accepted 2025-10-08 | Runtime 1 ms | Memory 25.5 MB

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }

        return 0;
    }
};