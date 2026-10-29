// Partition Equal Subset Sum (Medium)
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// Correct 2026-10-03 18:27:19 | C++

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2 !=0) return false;
        
        sum = sum / 2;
        int n = arr.size();
        
        vector<int> dp(sum+1,false);
        dp[0] = true;
        
        for(int i=0;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                dp[j] = dp[j-arr[i]] || dp[j];
            }
        }
        
        return dp[sum];
    }
};