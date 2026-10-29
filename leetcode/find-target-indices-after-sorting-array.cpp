// Find Target Indices After Sorting Array
// https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Accepted 2026-10-21 | Runtime 1 ms | Memory 15.2 MB

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                res.push_back(i);
            }
        }

        return res;
    }
};