// Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Accepted 2026-07-10 | Runtime 19 ms | Memory 25.3 MB

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        queue<pair<int,int>> q;
        distance[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<8;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx<0 || nx>=n || ny <0 || ny>=n || grid[nx][ny]!=0){
                    continue;
                }

                int newDistance = 1 + distance[row][col];
                if(distance[nx][ny] > newDistance){
                    distance[nx][ny] = newDistance;
                    q.push({nx,ny});
                }

            }
        }

        return distance[n-1][n-1]==INT_MAX ? -1 : distance[n-1][n-1];
    }
};