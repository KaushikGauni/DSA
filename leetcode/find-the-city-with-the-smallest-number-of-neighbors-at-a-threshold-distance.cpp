// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Accepted 2026-07-12 | Runtime 23 ms | Memory 21.2 MB

class Solution {
public:

    void shortest_path(vector<int> &reachable,int vertex, int n, vector<vector<pair<int,int>>>& adj, int distanceThreshold){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,vertex});
        vector<int> distance(n,INT_MAX);
        distance[vertex] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist > distance[node]){
                continue;
            }
            for(auto [neigh, oldDist] : adj[node]){
                int newDist = oldDist + dist;
                if(newDist < distance[neigh]){
                    distance[neigh] = newDist;
                    pq.push({newDist, neigh});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(i!=vertex && distance[i]<=distanceThreshold){
                reachable[vertex]++;
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int> reachable(n,0);
        for(int i=0;i<n;i++){
            shortest_path(reachable,i,n,adj,distanceThreshold);
        }

        int minimum = *min_element(reachable.begin(), reachable.end());

        for(int i=n-1;i>=0;i--){
            if(reachable[i]==minimum){
                return i;
            }
        }

        return -1;
    }
};