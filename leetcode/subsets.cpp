// Subsets
// https://leetcode.com/problems/subsets/
// Accepted 2026-06-27 | Runtime 3 ms | Memory 9.9 MB

class Solution {
public:
    // void buildsubsets(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int index){
    //     res.push_back(curr);
    //     for(int i=index;i<nums.size();i++){
    //         curr.push_back(nums[i]);
    //         buildsubsets(nums,curr,res,i+1);
    //         curr.pop_back();
    //     }
    // }
    vector<vector<int>> subsets(vector<int>& nums) {    
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> curr;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    curr.push_back(nums[j]);
                }
            }
            res.push_back(curr);
        }
        // buildsubsets(nums,curr,res,0);
        return res;
    }
};