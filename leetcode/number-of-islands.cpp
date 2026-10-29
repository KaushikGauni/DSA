// Number of Islands
// https://leetcode.com/problems/number-of-islands/
// Accepted 2026-07-01 | Runtime 25 ms | Memory 16.2 MB

class Solution {
public:

    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    islands++;
                }
            }
        } 

        return islands;
    }
};