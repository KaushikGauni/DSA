// Directed Graph Cycle (Medium)
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Correct 2026-10-06 11:50:22 | C++

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        
        for(auto edge : edges){
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)
                q.push(neigh);
            }
        }
        
        for(int i : indegree){
            if(i!=0) return true;
        }
        
        return false;
    }
};