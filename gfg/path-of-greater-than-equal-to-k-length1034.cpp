// Path of Total Weight Greater Than or Equal to K (Medium)
// https://www.geeksforgeeks.org/problems/path-of-greater-than-equal-to-k-length1034/1
// Correct 2026-10-07 12:37:47 | C++

class Solution {
  public:
  
    bool dfs(int node, vector<bool> &visited, vector<vector<pair<int,int>>> &adj, int k){
        if(k<=0) return true;
        
        visited[node] = true;
        
        for(auto ad : adj[node]){
            int neigh = ad.first;
            int dist = ad.second;
            
            
            if(!visited[neigh]){
                if(dfs(neigh, visited, adj, k-dist)) return true;
            }
        }
        
        visited[node] = false;
        
        return false;
        
        
    }
  
    bool pathMoreThanK(int V, vector<vector<int>>& edges, int k) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        
        vector<bool> visited(V,false);
        
        return dfs(0,visited,adj,k);
    }
};