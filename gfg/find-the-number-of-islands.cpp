// Count Islands (Medium)
// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
// Correct 2026-09-13 11:15:28 | C++

class Solution {
  public:
  
    void dfs(int i, int j, vector<vector<char>> &grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='W'){
            return;
        }
        
        grid[i][j] = 'W';
        
        dfs(i+1,j+1,grid);
        dfs(i-1,j-1,grid);
        dfs(i+1,j-1,grid);
        dfs(i-1,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
        return;
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    dfs(i,j,grid);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};