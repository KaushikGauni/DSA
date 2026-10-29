// Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/
// Accepted 2025-10-13 | Runtime 0 ms | Memory 99.2 MB

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
            return edges[0][0];
        }
        return edges[0][1];
    }
};