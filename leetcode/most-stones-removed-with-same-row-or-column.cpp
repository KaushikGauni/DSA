// Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Accepted 2026-10-08 | Runtime 34 ms | Memory 18.4 MB

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
            if(parent[x] == x) return x;

            return parent[x] = find(parent[x]);
        }

        void unionBySize(int u, int v){
            u = find(u);
            v = find(v);

            if(u == v) return;

            if(size[u] > size[v]){
                parent[v] = u;
                size[u] += size[v];
            }

            else{
                parent[u] = v;
                size[v] += size[u];
            }

            return;
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    ds.unionBySize(i,j);
                }
            }
        }

        int count = 0;

        for(int i = 0;i<n;i++){
            if(ds.find(i) == i) count++;
        }

        return n - count;
    }
};