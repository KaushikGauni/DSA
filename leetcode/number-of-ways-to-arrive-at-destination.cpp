// Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Accepted 2026-07-11 | Runtime 9 ms | Memory 37.4 MB

class Solution {
public:
    const int MOD = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;
        vector<long long> distance(n,LLONG_MAX);
        vector<long long> ways(n,0);


        pq.push({0,0});
        distance[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();

            if(dist > distance[node]){
                continue;
            }

            for(auto [neigh,cost] : adj[node]){
                long long newCost = cost + dist;
                if(newCost < distance[neigh]){
                    distance[neigh] = newCost;
                    ways[neigh] = ways[node];
                    pq.push({newCost, neigh});
                }
                else if(newCost == distance[neigh]){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }

        }

        return ways[n-1];
    }
};