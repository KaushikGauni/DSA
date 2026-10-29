// Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/
// Accepted 2026-07-14 | Runtime 7 ms | Memory 14.2 MB

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int maxPath = grid[0][0];
        int n = grid.size();

        vector<vector<bool>> visited(n,vector<bool>(n,false));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0] = true;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!pq.empty()){
            int val = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row==n-1 && col==n-1){
                return max(val,maxPath);
            }
            maxPath = max(maxPath, val);
            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx<0 || nx>=n || ny<0 || ny>=n || visited[nx][ny]){
                    continue;
                }
                visited[nx][ny] = true;
                pq.push({grid[nx][ny], nx, ny});
            }
        }
        
        return maxPath;

    }
};