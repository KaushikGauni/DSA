// Combination Sum
// https://leetcode.com/problems/combination-sum/
// Accepted 2026-08-04 | Runtime 3 ms | Memory 14.4 MB

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        build(0,candidates,target,curr);
        return res; 
    }

    void build(int i, vector<int>& candidates, int target, vector<int> &curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int idx=i;idx<candidates.size();idx++){
            if(target < candidates[idx]){
                continue;
            }
            curr.push_back(candidates[idx]);
            build(idx,candidates,target-candidates[idx],curr);
            curr.pop_back();
        }
    }
};