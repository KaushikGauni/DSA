// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 14 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i : nums){
            auto it = lower_bound(res.begin(), res.end(), i);
            if(it == res.end()){
                res.push_back(i);
            }
            else{
                *it = i;
            }
        }

        return res.size();
    }
};