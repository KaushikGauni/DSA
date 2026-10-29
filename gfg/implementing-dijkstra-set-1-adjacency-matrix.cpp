// Dijkstra Algorithm (Medium)
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Correct 2026-09-13 10:23:02 | C++

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<int> distance(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        distance[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(dist > distance[node]){
                continue;
            }
            
            for(auto p : adj[node]){
                int neigh = p.first;
                int edgeWeight = p.second;
                
                if(dist + edgeWeight < distance[neigh]){
                    distance[neigh] = dist + edgeWeight;
                    pq.push({distance[neigh],neigh});
                }
            }
        }
        
        return distance;
    }
};