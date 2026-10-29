// Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
// Accepted 2026-01-26 | Runtime 0 ms | Memory 14.1 MB

class Solution {
public:

    void backtrack(int idx, int target, vector<int> &curr, vector<vector<int>> &res, vector<int> &candidates){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }

            curr.push_back(candidates[i]);
            backtrack(i+1, target-candidates[i], curr, res, candidates);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0,target, curr, res, candidates);
        return res;
    }
};