// Longest Possible Route in a Matrix with Hurdles (Medium)
// https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1
// Correct 2026-09-11 11:02:03 | C++

class Solution {
  public:
  
    int dist;
  
    void dfs(vector<vector<int>>&mat, int i, int j, int m, int n, int d){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==0){
            return;
        }
        
        if(i==m && j==n){
            dist = max(dist, d);
            return;
        }
        
        mat[i][j] = 0; 
        
        dfs(mat,i+1,j,m,n,d+1);
        dfs(mat,i-1,j,m,n,d+1);
        dfs(mat,i,j+1,m,n,d+1);
        dfs(mat,i,j-1,m,n,d+1);
        
        mat[i][j] = 1;
        
    }
  
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        dist = -1;
        dfs(mat,xs,ys,xd,yd,0);
        return dist;
    }
};