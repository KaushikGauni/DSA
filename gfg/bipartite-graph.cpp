// Bipartite Graph (Medium)
// https://www.geeksforgeeks.org/problems/bipartite-graph/1
// Correct 2026-10-07 15:21:28 | C++

class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int c){
        color[node] = c;
        
        for(int neigh : adj[node]){
            if(color[neigh] == c){
                return false;
            }
            if(color[neigh]==0){
                if(!dfs(neigh,adj,color,-c)){
                    return false;
                }
            }
        }
        
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V,0);
        vector<vector<int>> adj(V);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for(int i=0;i<V;i++){
            if(color[i]==0){
                if(!dfs(i,adj,color,1)){
                    return false;
                }
            }
        }
        
        return true;
    }
};