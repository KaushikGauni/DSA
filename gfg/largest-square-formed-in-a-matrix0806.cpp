// Largest Square of 1s in Matrix (Medium)
// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
// Correct 2026-10-04 11:32:34 | C++

class Solution {
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) dp[i][j] = 0;
                
                else{
                    if(i>0 && j>0){
                        dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    }
                    else{
                        dp[i][j] = 1;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};