// Floyd Warshall (Medium)
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Correct 2026-09-13 17:43:01 | C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e8 && dist[k][j]!=1e8){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        
        return;
    }
};