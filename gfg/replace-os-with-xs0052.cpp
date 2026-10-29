// Replace O's with X's (Medium)
// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// Correct 2026-09-22 14:31:37 | C++

class Solution {
  public:
  
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size() || grid[i][j]!='O'){
            return;
        }
        grid[i][j] = '#';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
  
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O'){
                dfs(i,0,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][m-1]=='O'){
                dfs(i,m-1,grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O'){
                dfs(0,j,grid);
            }
        }
        
        for(int j=0;j<m;j++){
            if(grid[n-1][j]=='O'){
                dfs(n-1,j,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O'){
                    grid[i][j] = 'X';
                }
                else if(grid[i][j]=='#'){
                    grid[i][j] = 'O';
                }
            }
        }
        
        return;
    }
};