// Ceil in Sorted Array (Easy)
// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// Correct 2026-09-22 15:28:18 | C++

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int left = 0, right = arr.size()-1;
        int ans = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= x){
                ans = mid;
                right = mid - 1;
            }
            
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};