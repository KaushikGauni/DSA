// Max Area of Island
// https://leetcode.com/problems/max-area-of-island/
// Accepted 2026-07-01 | Runtime 0 ms | Memory 27.2 MB

class Solution {
public:

    int dfs(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            grid[i][j] = 0;
            return 1 + dfs(grid,i+1,j,n,m) + dfs(grid,i-1,j,n,m) + dfs(grid,i,j+1,n,m) + dfs(grid,i,j-1,n,m); 
        }

        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea, dfs(grid,i,j,n,m));
                }
            }
        }

        return maxArea;
    }
};