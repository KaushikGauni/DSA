// Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/
// Accepted 2026-08-12 | Runtime 11 ms | Memory 22.1 MB

class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &heights, int last){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || visited[i][j] || heights[i][j]<last){
            return;
        }
        visited[i][j] = true;
        dfs(i+1,j,visited,heights,heights[i][j]);
        dfs(i-1,j,visited,heights,heights[i][j]);
        dfs(i,j+1,visited,heights,heights[i][j]);
        dfs(i,j-1,visited,heights,heights[i][j]);
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> atl(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights,INT_MIN);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,m-1,atl,heights,INT_MIN);
        }

        for(int j=0;j<m;j++){
            dfs(0,j,pac,heights,INT_MIN);
        }

        for(int j=0;j<m;j++){
            dfs(n-1,j,atl,heights,INT_MIN);
        }

        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;

    }
};