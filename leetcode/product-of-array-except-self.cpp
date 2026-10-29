// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Accepted 2026-09-20 | Runtime 0 ms | Memory 40.3 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int curr = 1;
        for(int i = 0;i<nums.size();i++){
            ans[i] *= curr;
            curr *= nums[i];
        }
        curr = 1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] *= curr;
            curr *= nums[i];
        }

        return ans;
    }
};