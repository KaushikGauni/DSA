// Minimum Path Cost in a Grid
// https://leetcode.com/problems/minimum-path-cost-in-a-grid/
// Accepted 2025-10-31 | Runtime 25 ms | Memory 84.6 MB

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int move(vector<vector<int>> &dp, vector<vector<int>> &grid, vector<vector<int>> &moveCost, int i, int j, int n, int m){
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res = INT_MAX;
        for(int k=0;k<m;k++){
            int temp = moveCost[grid[i][j]][k] + move(dp, grid, moveCost, i+1, k, n , m);
            res = min(res, temp);
        }
        return dp[i][j] = res + grid[i][j];
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans, move(dp,grid,moveCost,0,i,n,m));
        }
        return ans;
    }
};