// Celebrity Problem (Medium)
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// Correct 2026-09-09 12:05:45 | C++

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int a = 0, b = n-1;
        
        while(a<b){
            if(mat[a][b]) a++;
            else b--;
        }
        
        int candidate = a;
        
        for(int i=0;i<n;i++){
            if(i!=candidate){
                if(mat[i][candidate]!=1 || mat[candidate][i]!=0){
                    return -1;
                }
            }
        }
        
        return candidate;
    }
};