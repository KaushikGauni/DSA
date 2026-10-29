// Edit Distance
// https://leetcode.com/problems/edit-distance/
// Accepted 2026-07-24 | Runtime 0 ms | Memory 10.4 MB

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    int del = prev[j];
                    int ins = curr[j-1];
                    int sub = prev[j-1];
                    curr[j] = 1 + min(del,min(ins,sub));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};