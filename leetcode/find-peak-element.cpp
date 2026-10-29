// Find Peak Element
// https://leetcode.com/problems/find-peak-element/
// Accepted 2026-06-20 | Runtime 0 ms | Memory 12.6 MB

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid+1] > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }

        return low;
    }
};