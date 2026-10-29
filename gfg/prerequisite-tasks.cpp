// Prerequisite Tasks (Medium)
// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
// Correct 2026-09-13 11:07:33 | C++

class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        
        for(auto p : pre){
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neigh : adj[node]){
                if(--indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        for(int i : indegree){
            if(i!=0){
                return false;
            }
        }
        
        return true;
    }
};