// Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/
// Accepted 2026-10-09 | Runtime 0 ms | Memory 17.3 MB

class Solution {
public:

    bool dfs(int i, vector<int> &color, vector<vector<int>>& graph, int c){
        color[i] = c;

        for(int neigh : graph[i]){
            if(color[neigh] == c){
                return false;
            }
            if(color[neigh] == 0){
                if(!dfs(neigh,color,graph,-c)) return false;
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);

        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(i,color,graph,1)){
                    return false;
                }
            }
        }

        return true;
    }
};