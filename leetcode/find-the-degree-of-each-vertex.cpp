// Find the Degree of Each Vertex
// https://leetcode.com/problems/find-the-degree-of-each-vertex/
// Accepted 2026-08-20 | Runtime 7 ms | Memory 54.5 MB

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> degree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    degree[j]++;
                }
            }
        }

        return degree;
    }
};