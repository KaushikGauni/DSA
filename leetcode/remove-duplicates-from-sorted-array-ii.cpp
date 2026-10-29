// Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Accepted 2025-10-30 | Runtime 11 ms | Memory 19.5 MB

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        int j = 2;
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[j-2]){
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};