// Making A Large Island
// https://leetcode.com/problems/making-a-large-island/
// Accepted 2026-07-15 | Runtime 281 ms | Memory 159.5 MB

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

    int find (int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unionBySize(int u, int v){
        u = find(u);
        v = find(v);

        if(u==v){
            return;
        }
        if(size[v]<size[u]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
};


class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n+2);

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node = i * n + j;
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                            int adj = nx * n + ny;
                            ds.unionBySize(adj,node);
                        }
                    }
                }
            }
        }
        
        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> parents;
                    int node = i * n + j;
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                            int adj = nx * n + ny;
                            parents.insert(ds.find(adj));
                        }
                    }
                    int area = 1;
                    for(int p : parents){
                        area += ds.size[p];
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea==0 ? n*n : maxArea;
    }
};