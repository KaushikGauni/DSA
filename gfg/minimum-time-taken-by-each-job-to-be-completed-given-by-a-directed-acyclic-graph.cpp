// Earliest Completion Time of Jobs (Medium)
// https://www.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1
// Correct 2026-09-13 10:59:26 | C++

class Solution {
  public:
    vector<int> minTime(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V+1);
        vector<int> indegree(V+1,0);
        
        for(auto edge : edges){
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        
        queue<int> q;
        vector<int> time(V+1,1);
        
        for(int i=1;i<=V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int node = q.front();
                q.pop();
                
                for(int neigh : adj[node]){
                    indegree[neigh]--;
                    
                    if(indegree[neigh]==0){
                        time[neigh] = max(time[neigh],time[node] + 1);
                        q.push(neigh);
                    }
                }
            }
        }
        time.erase(time.begin());
        return time;
    }
};