// Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/
// Accepted 2026-07-10 | Runtime 45 ms | Memory 24.5 MB

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> efforts(n,vector<int>(m,INT_MAX));
        efforts[0][0] = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            if(row==n-1 && col==m-1){
                return effort;
            }
            pq.pop();

            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || heights[nx][ny]==-1){
                    continue;
                }
                int currEffort = abs(heights[nx][ny]-heights[row][col]);
                currEffort = max(currEffort, effort);
                if(efforts[nx][ny] > currEffort){
                    efforts[nx][ny] = currEffort;
                    pq.push({currEffort,{nx,ny}});
                }
            }
        }

        return efforts[n-1][m-1];


    }
};