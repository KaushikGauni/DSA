// Array Removals to Limit Max-Min Diff (Medium)
// https://www.geeksforgeeks.org/problems/array-removals/1
// Correct 2026-10-04 10:32:06 | C++

class Solution {
  public:
    int removals(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 0, right = 0;
        int maxLen = 0;
        
        for(right = 0;right < n;right++){
            while(arr[right] - arr[left] > k) left++;
            
            maxLen = max(maxLen, right-left+1);
        }
        
        return n - maxLen;
    }
};
