// Max Sum Without 3 Adjacent (Medium)
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1
// Correct 2026-10-04 18:49:03 | C++

class Solution {
  public:
    int recurse(int i, vector<int>& arr, int consec, vector<vector<int>> &dp){
        if(i>=arr.size()) return 0;
        
        if(dp[i][consec]!=-1) return dp[i][consec];
        
        int notpick = recurse(i+1,arr,0,dp);
        int pick = 0;
        
        if(consec < 2){
            pick = arr[i] + recurse(i+1,arr,consec+1,dp);
        }
        
        return dp[i][consec] = max({pick,notpick});
        
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                int notpick = dp[i+1][0];
                int pick = 0;
                
                if(j<2){
                    pick = arr[i] + dp[i+1][j+1];
                }
                
                dp[i][j] = max(pick,notpick);
            }
        }
        
        return dp[0][0];
    }
};