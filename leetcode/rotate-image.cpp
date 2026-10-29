// Rotate Image
// https://leetcode.com/problems/rotate-image/
// Accepted 2026-09-08 | Runtime 0 ms | Memory 10.2 MB

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        for(auto &arr : matrix){
            reverse(arr.begin(), arr.end());
        }

        return;
    }
};