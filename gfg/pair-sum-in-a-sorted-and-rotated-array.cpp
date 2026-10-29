// Pair Sum in Sorted and Rotated (Medium)
// https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/1
// Correct 2026-09-22 09:32:40 | C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int left = 0, right = n-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[right]){
                left = mid + 1;
            }
            else if(arr[mid] < arr[right]){
                right = mid;
            }
            else{
                right--;
            }
        }
        
        int low = left;
        int high = (left - 1 + n) % n;
        
        while(low != high){
            int sum = arr[low] + arr[high];
            if(sum == target){
                return true;
            }
            else if(sum < target){
                low = (low + 1) % n;
            }
            else{
                high = (high - 1 + n) % n;
            }
        }
        
        return false;
    }
};