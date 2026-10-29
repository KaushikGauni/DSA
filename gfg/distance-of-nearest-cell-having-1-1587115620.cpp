// Distance of Nearest 1 in Grid (Medium)
// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// Correct 2026-09-09 12:28:51 | C++

class Solution {
  public:
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
  
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx <0 || nx >= n || ny < 0 || ny >= m || res[nx][ny]!=-1){
                    continue;
                }
                
                res[nx][ny] = res[row][col] + 1;
                
                q.push({nx,ny});
            }
        }
        
        return res;
    }
};