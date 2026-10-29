// Negative Weight Cycle (Medium)
// https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1
// Correct 2026-10-07 15:07:00 | C++

class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> distance(V,0);
        
        for(int i=0;i<V;i++){
            bool updated = false;
            
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[v] > distance[u] + w){
                    updated = true;
                    distance[v] = distance[u] + w;
                    
                    if(i == V-1) return true;
                }
            }
            
            if(!updated) return false;
        }
        
        return false;
    }
};