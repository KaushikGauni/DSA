// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 17.6 MB

class Solution {
public:
    int searchLeft(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1, ans = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            
        }

        return ans;
    }


    int searchRight(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1, ans = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLeft(nums,target), searchRight(nums,target)};
    }
};