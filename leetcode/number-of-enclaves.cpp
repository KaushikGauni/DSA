// Number of Enclaves
// https://leetcode.com/problems/number-of-enclaves/
// Accepted 2026-07-02 | Runtime 10 ms | Memory 34.1 MB

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int row, int col, vector<vector<int>>&grid, int n, int m){
        if(row<0 || col<0 || row>=n||col>=m || grid[row][col]!=1){
            return;
        }
        grid[row][col] = 0;

        for(int i=0;i<4;i++){
            dfs(row+dx[i],col+dy[i],grid,n,m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]){
                dfs(i,0,grid,n,m);
            }
            if(grid[i][m-1]){
                dfs(i,m-1,grid,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]){
                dfs(0,i,grid,n,m);
            }
            if(grid[n-1][i]){
                dfs(n-1,i,grid,n,m);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};