// Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/
// Accepted 2026-10-26 | Runtime 0 ms | Memory 16.5 MB

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int res = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()){
            int s = q.size();
            bool rotten = false;
            while(s--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        rotten = true;
                        fresh--;
                    }

                }
            }

            if(rotten) res++;
        }

        return fresh == 0 ? res : -1;
    }
};