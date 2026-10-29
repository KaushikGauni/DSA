// Minimum Spanning Tree - Kruskal's Algorithm (Medium)
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
// Correct 2026-10-08 11:29:44 | C++

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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(), edges.end(), [](auto a, auto b){
            return a[2] < b[2];
        });
        
        DisjointSet ds(V);
        
        int res = 0;
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(ds.unionBySize(u,v)){
                res += w;
            }
        }
        
        return res;
    }
};