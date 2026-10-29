// Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/
// Accepted 2026-07-15 | Runtime 0 ms | Memory 15.3 MB

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[j] = grid[i][j];
                }
                else if(i==0){
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else if(j==0){
                    dp[j] = dp[j] + grid[i][j];
                }
                else{
                    dp[j] = min(dp[j],dp[j-1]) + grid[i][j];
                }
            }
        }

        return dp[m-1];
    }
};