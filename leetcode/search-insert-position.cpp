// Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 13.8 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                high = mid - 1;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
        }

        return low;
    }
};