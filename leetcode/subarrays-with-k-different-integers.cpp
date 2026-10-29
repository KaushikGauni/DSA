// Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/
// Accepted 2026-08-03 | Runtime 87 ms | Memory 56.1 MB

class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int,int> hm;
        int left = 0, right = 0, res = 0;
        for(right=0;right<nums.size();right++){
            hm[nums[right]]++;

            while(hm.size() > k){
                hm[nums[left]]--;
                if(hm[nums[left]]==0){
                    hm.erase(nums[left]);
                }
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};