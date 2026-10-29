// Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Accepted 2026-07-02 | Runtime 8 ms | Memory 32.9 MB

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j] = 0;
                }
                else{
                    if(i-1>=0 && j-1>=0){
                        dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for(auto arr : dp){
            for(int i : arr){
                ans += i;
            }
        }
        return ans;
    }
};