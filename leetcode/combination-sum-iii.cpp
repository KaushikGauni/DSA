// Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/
// Accepted 2026-08-04 | Runtime 0 ms | Memory 8.7 MB

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(curr,k,n,1);
        return res;
    }
    void backtrack(vector<int> &curr, int k, int n, int idx){
        if(k<0 || n<0){
            return;
        }
        if(k==0 && n==0){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<10;i++){
            if(i <= n){
                curr.push_back(i);
                backtrack(curr,k-1,n-i,i+1);
                curr.pop_back();
            }
        }
    }
};