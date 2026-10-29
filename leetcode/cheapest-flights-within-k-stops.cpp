// Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Accepted 2026-09-18 | Runtime 160 ms | Memory 54.1 MB

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);

        distance[src] = 0;
        
        for(int i=0;i<=k;i++){
            vector<int> temp = distance;
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if(distance[u] != INT_MAX && distance[u] + cost < temp[v]){
                    temp[v] = distance[u] + cost;
                }
            }
            distance = temp;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};