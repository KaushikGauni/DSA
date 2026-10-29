// Gold Mine Problem (Medium)
// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1
// Correct 2026-10-01 11:53:54 | C++

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            dp[i][m-1] = mat[i][m-1];
        }
        
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                int right = dp[i][j+1];
                int rightUp = 0;
                if(i>0)
                    rightUp = dp[i-1][j+1];
                int rightDown = 0;
                if(i < n-1)
                    rightDown = dp[i+1][j+1];
                
                dp[i][j] = mat[i][j] + max({right,rightUp,rightDown});
            }
        }
        
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i][0]);
        }
        
        return ans;
    }
};