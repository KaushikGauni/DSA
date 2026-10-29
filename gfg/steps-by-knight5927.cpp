// Min Steps by Knight (Medium)
// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
// Correct 2026-09-12 16:43:59 | C++

class Solution {
  public:
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int i = knightPos[0];
        int j = knightPos[1];
        int k = targetPos[0];
        int l = targetPos[1];
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
        q.push({{i,j},0});
        visited[i][j] = true;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            if(row==k && col==l){
                return distance;
            }
            
            
            int dx[] = {2,2,-2,-2,1,1,-1,-1};
            int dy[] = {1,-1,1,-1,2,-2,2,-2};
            
            for(int i=0;i<8;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]){
                    continue;
                }
                visited[nx][ny] = true;
                q.push({{nx,ny},distance+1});
                
            }
        }
        
        
        return -1;
        
    }
};