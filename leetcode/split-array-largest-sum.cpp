// Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/
// Accepted 2026-06-20 | Runtime 0 ms | Memory 10.5 MB

class Solution {
public:

    bool possible(int mid, vector<int> &nums, int k){
        int curr = 0;
        int parts = 1;
        for(int i=0;i<nums.size();i++){
            if(curr + nums[i] <= mid){
                curr += nums[i];
            }
            else{
                parts++;
                curr = nums[i];
            }
        }

        return parts<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(possible(mid,nums,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};