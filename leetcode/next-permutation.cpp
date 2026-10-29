// Next Permutation
// https://leetcode.com/problems/next-permutation/
// Accepted 2026-10-01 | Runtime 0 ms | Memory 15.6 MB

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n - 2;

        while(k>=0 && nums[k]>=nums[k+1]){
            k--;
        }

        if(k==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        int i = n-1;

        while(i>=0 && nums[i]<=nums[k]){
            i--;
        }

        swap(nums[i],nums[k]);

        reverse(nums.begin()+k+1, nums.end());
    }
};