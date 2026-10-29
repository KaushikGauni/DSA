// Concatenate Array With Reverse
// https://leetcode.com/problems/concatenate-array-with-reverse/
// Accepted 2026-08-20 | Runtime 0 ms | Memory 30.1 MB

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n*2);
        for(int i=0;i<n;i++){
            ans[i] = nums[i];
            ans[i+n] = nums[n-i-1];
        }

        return ans;
    }
};