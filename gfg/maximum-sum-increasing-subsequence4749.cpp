// Max Sum Increasing Subsequence (Medium)
// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Correct 2026-10-04 18:15:03 | C++

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> dp = arr;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = max(dp[i], ans);
        }
        
        return ans;
    }
};