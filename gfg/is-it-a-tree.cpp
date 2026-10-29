// Graph is Tree or Not (Medium)
// https://www.geeksforgeeks.org/problems/is-it-a-tree/1
// Correct 2026-09-02 15:13:38 | C++

class Solution {
  public:
  
    void dfs(vector<bool> &visited, int i, vector<vector<int>> &adj){
        visited[i] = true;
        
        for(auto neigh : adj[i]){
            if(!visited[neigh]){
                dfs(visited,neigh,adj); 
            }
        }
    }
  
    bool isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        if(n-1!=m){
            return false;
        }
        
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n,false);
        dfs(visited,0,adj);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            } 
        }
        
        return true;
        
    }
};
