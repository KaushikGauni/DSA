// Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/
// Accepted 2025-10-13 | Runtime 472 ms | Memory 328 MB

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjlist;
        for(auto &edge : edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        stack<int> st;
        st.push(source);
        visited[source] = true;

        while(!st.empty()){
            int top = st.top();
            if(top==destination){
                return true;
            }
            st.pop();
            for(auto node : adjlist[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node);
                }
            }
        }

        return false;
    }
};