// Two Sum
// https://leetcode.com/problems/two-sum/
// Accepted 2026-10-24 | Runtime 1 ms | Memory 14.8 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        for(int i=0;i<nums.size();i++){
            int k = target - nums[i];
            if(hm.count(k)) return {i,hm[k]};
            hm[nums[i]] = i;
        }
        return {};
    }
};