// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Accepted 2026-09-13 | Runtime 20 ms | Memory 46.8 MB

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
            if(parent[x]==x){
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        void unionBySize(int u, int v){
            u = find(u);
            v = find(v);

            if(u==v){
                return;
            }

            if(size[u] < size[v]){
                parent[u] = v;
                size[v] += size[u];
            }

            else{
                parent[v] = u;
                size[u] += size[v];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        DisjointSet ds(n);

        for(auto arr : connections){
            ds.unionBySize(arr[0],arr[1]);
        }
        int comp = 0;
        for(int i =0;i<n;i++){
            if(ds.find(i)==i){
                comp++;
            }
        }

        return comp - 1;
    }
};