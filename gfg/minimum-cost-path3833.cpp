// Minimum Cost Path with 4 Moves (Hard)
// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
// Correct 2026-08-25 11:25:29 | C++



class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        distance[0][0] = grid[0][0];
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int dist = distance[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n || distance[nx][ny]<=dist+grid[nx][ny]){
                    continue;
                }
                int newDistance = dist + grid[nx][ny];
                distance[nx][ny] = newDistance;
                q.push({nx,ny});
            }
        }
        
        return distance[n-1][n-1];
    }
};