// Subsets II
// https://leetcode.com/problems/subsets-ii/
// Accepted 2026-08-04 | Runtime 0 ms | Memory 10.8 MB

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0,nums,curr);
        return res;
    }

    void backtrack(int idx, vector<int> &nums, vector<int>& curr){
        res.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr);
            curr.pop_back();
        }
    }
};