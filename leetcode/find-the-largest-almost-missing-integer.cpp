// Find the Largest Almost Missing Integer
// https://leetcode.com/problems/find-the-largest-almost-missing-integer/
// Accepted 2026-08-18 | Runtime 0 ms | Memory 29 MB

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        for(int i : nums){
            freq[i]++;
        }
        if(k==1){
            int res = -1;
            for(int i=0;i<51;i++){
                if(freq[i]==1){
                    res = max(i,res);
                }
            }
            return res;
        }
        if(k==nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        int res = -1;

        if(freq[nums[0]]==1){
            res = max(res, nums[0]);
        }

        if(freq[nums[nums.size()-1]]==1){
            res = max(res, nums[nums.size()-1]);
        }

        return res;
    }
};