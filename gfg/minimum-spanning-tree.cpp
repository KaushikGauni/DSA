// Minimum Spanning Tree (Medium)
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Correct 2026-09-13 17:35:56 | C++

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        vector<bool> visited(V,false);
        
        int result = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int edgeWt = pq.top().first;
            
            pq.pop();
            
            if(visited[node]){
                continue;
            }
            
            visited[node] = true;
            result += edgeWt;
            
            for(auto edge : adj[node]){
                int neigh = edge.first;
                int wt = edge.second;
                
                if(!visited[neigh]){
                    pq.push({wt,neigh});
                }
            }
        }
        
        return result;
        
    }
};