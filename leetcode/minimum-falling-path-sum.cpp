// Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/
// Accepted 2025-10-20 | Runtime 0 ms | Memory 15 MB

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left = INT_MAX;
                if(j>0){
                    left = dp[i-1][j-1];
                }
                int mid = dp[i-1][j];
                int right = INT_MAX;
                if(j<n-1){
                    right = dp[i-1][j+1];
                }
                dp[i][j] = matrix[i][j] + min(left,min(mid,right));
            }  
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,dp[n-1][i]);
        }
        
        return res;
    }
};