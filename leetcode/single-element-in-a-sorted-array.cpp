// Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Accepted 2026-06-20 | Runtime 0 ms | Memory 26.2 MB

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = low + (high - low) / 2;
            if(mid%2!=0){
                mid--;
            }         

            if(nums[mid]==nums[mid+1]){
                low = mid + 2;
            }   
            else{
                high = mid;
            }
        }

        return nums[low];

    }
};