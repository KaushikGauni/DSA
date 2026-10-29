// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 15.2 MB

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low) / 2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                high--;
                low++;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};