// Topological Sort (Medium)
// https://www.geeksforgeeks.org/problems/topological-sort/1
// Correct 2026-09-13 10:30:56 | C++

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        
        vector<vector<int>> adj(V);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        
        for(int i =0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> res;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(int neigh : adj[node]){
                indegree[neigh]--;
                
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
            
        }
        
        return res;
        
        
    }
};