// Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Accepted 2026-06-18 | Runtime 1 ms | Memory 128.2 MB

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int pos = 0, neg = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                result[pos] = nums[i];
                pos += 2;
            }
            else{
                result[neg] = nums[i];
                neg += 2;
            }
        }

        return result;
    }
};