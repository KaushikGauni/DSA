// Max Subarray Sum by Removing At Most One (Medium)
// https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1
// Correct 2026-07-03 06:47:41 | C++

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> bw(n), fw(n);
        bw[0] = arr[0];
        int ans = arr[0];
        for(int i=1;i<n;i++){
            bw[i] = max(arr[i],bw[i-1] + arr[i]);
            ans = max(ans,bw[i]);
        }
        
        fw[n-1] = arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            fw[i] = max(arr[i],fw[i+1]+arr[i]);
        }
        
        
        for(int i=1;i<n-1;i++){
            ans = max(ans, bw[i-1]+fw[i+1]);
        }
        
        
        return ans;
        
    }
};