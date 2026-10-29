// Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/
// Accepted 2026-07-07 | Runtime 7 ms | Memory 51.9 MB

class Solution {
public:

    bool dfs(int i, vector<vector<int>>& graph, vector<int> &state){
        if(state[i]!=0){
            return state[i]==2;
        }

        state[i] = 1;

        for(int neigh : graph[i]){
            if(state[neigh]==1 || !dfs(neigh,graph,state)){
                return false;
            }
        }

        state[i] = 2;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(dfs(i,graph,state)){
                res.push_back(i);
            }
        }

        return res;
    }
};