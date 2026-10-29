// Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/
// Accepted 2026-08-01 | Runtime 110 ms | Memory 116.8 MB

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int right = 0, left = 0;
        for(right=0;right<nums.size();right++){
            if(window.count(nums[right])){
                return true;
            }
            window.insert(nums[right]);

            while(window.size()>k){
                window.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};