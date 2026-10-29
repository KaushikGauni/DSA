// Number of Provinces
// https://leetcode.com/problems/number-of-provinces/
// Accepted 2026-06-30 | Runtime 0 ms | Memory 19.4 MB

class Solution {
public:

    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int node){
        visited[node] = true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i] && !visited[i]){
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int provinces = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                provinces++;
            }
        }

        return provinces;
    }
};