// Number of Distinct Islands (Medium)
// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Correct 2026-10-06 11:13:50 | C++

class Solution {
  public:
  
    void dfs(int i, int j,int bi, int bj, set<pair<int,int>> &temp, vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='W') return;
        
        temp.insert({bi-i,bj-j});
        grid[i][j] = 'W';
        
        dfs(i+1,j,bi,bj,temp,grid);
        dfs(i-1,j,bi,bj,temp,grid);
        dfs(i,j+1,bi,bj,temp,grid);
        dfs(i,j-1,bi,bj,temp,grid);
        
    }
  
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        set<set<pair<int,int>>> hs;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    set<pair<int,int>> temp;
                    dfs(i,j,i,j,temp,grid);
                    hs.insert(temp);
                }
            }
        }
        
        return hs.size();
    }
};
