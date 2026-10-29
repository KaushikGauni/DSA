// 01 Matrix
// https://leetcode.com/problems/01-matrix/
// Accepted 2026-10-15 | Runtime 14 ms | Memory 34.6 MB

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int dist = distance[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && distance[nx][ny]==INT_MAX){
                    distance[nx][ny] = dist + 1;
                    q.push({nx,ny});
                }
            }
        }

        return distance;
    }
};