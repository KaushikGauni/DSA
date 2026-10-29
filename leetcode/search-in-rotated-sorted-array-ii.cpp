// Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Accepted 2026-10-01 | Runtime 0 ms | Memory 18.1 MB

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target){
                return true;
            }
            if(arr[mid] == arr[high]){
                high--;
            }
            else if(arr[mid] < arr[high]){
                if(arr[mid] < target && target <=arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1; 
                }
            }
            else{
                if(arr[low] <= target && target < arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};