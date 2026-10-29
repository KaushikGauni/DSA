// Undirected Graph Cycle (Medium)
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Correct 2026-10-06 11:45:41 | C++

class DisjointSet{
    public:
        vector<int> parent;
        vector<int> size;

        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        bool unionBySize(int u, int v){
            u = find(u);
            v = find(v);
            if(u==v) return false;

            if(size[u] > size[v]){
                parent[v] = u;
                size[u] += size[v];
            }
            else{
                parent[u] = v;
                size[v] += size[u];
            }

            return true;
        }
};

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>> &edges) {
        // code here
        DisjointSet ds(V);
        for(auto edge : edges){
            if(!ds.unionBySize(edge[0],edge[1])){
                return true;
            }
        }
        return false;
    }
};