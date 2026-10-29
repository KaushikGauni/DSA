// Minimum Subsequence in Non-Increasing Order
// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
// Accepted 2025-10-09 | Runtime 3 ms | Memory 15.8 MB

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        sort(nums.begin(), nums.end());
        int max = 0,i=0;
        for(i=nums.size()-1;i>=0;i--){
            max += nums[i];
            if(max > (sum-max)){
                break;
            }
        }
        vector<int> res;
        for(int j=i;j<nums.size();j++){
            res.push_back(nums[j]);
        }
        sort(res.rbegin(), res.rend());
        return res;
    }
};