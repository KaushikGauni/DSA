// Max Path Sum in Grid with 3 Moves (Medium)
// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
// Correct 2026-10-01 18:35:39 | C++

class Solution {
  public:
  
  
    int recurse(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = mat[i][j] + max({recurse(i+1,j-1,mat,dp),
                                recurse(i+1,j,mat,dp),
                                recurse(i+1,j+1,mat,dp)
        });
    }
  
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            dp[n-1][j] = mat[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int down = dp[i+1][j];
                int downLeft = 0, downRight = 0;
                if(j>0)
                downLeft = dp[i+1][j-1];
                if(j<m-1)
                downRight = dp[i+1][j+1];
                
                dp[i][j] = mat[i][j] + max({down,downLeft,downRight});
            }
        }
        
        for(int j=0;j<m;j++){
            ans = max(ans, dp[0][j]);
        }
        
        return ans;
    }
};