// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Accepted 2026-09-10 | Runtime 0 ms | Memory 22.7 MB

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]){
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};