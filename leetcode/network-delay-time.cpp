// Network Delay Time
// https://leetcode.com/problems/network-delay-time/
// Accepted 2026-07-10 | Runtime 89 ms | Memory 48.1 MB

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto arr : times){
            adj[arr[0]].push_back({arr[1],arr[2]});
        } 

        vector<int> distance(n+1, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        distance[k] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist > distance[node]){
                continue;
            }


            for(auto arr : adj[node]){
                int newDistance = dist + arr.second;
                if(newDistance < distance[arr.first]){
                    distance[arr.first] = newDistance;
                    pq.push({newDistance, arr.first});
                }
            }
        }

        int minTime = INT_MIN;

        for(int i=1;i<n+1;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            if(minTime < distance[i]){
                minTime = distance[i];
            }
        }

        return minTime;
    }
};