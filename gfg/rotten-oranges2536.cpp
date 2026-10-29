// Rotten Oranges (Medium)
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
// Correct 2026-09-09 12:37:18 | C++

class Solution {
  public:
  
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        int t = 0;
        
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
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny]!=1){
                        continue;
                    }
                    
                    mat[nx][ny] = 2;
                    rotten = true;
                    q.push({nx,ny});
                }
            }
            
            if(rotten){
                t++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    return -1;
                }
            }
        }
        
        return t;
    }
};