// Edit Distance (Hard)
// https://www.geeksforgeeks.org/problems/edit-distance3702/1
// Correct 2026-10-01 11:36:15 | C++

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> curr(m+1), prev(m+1);
        
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            prev = curr;
        }
        
        return prev[m];
        
    }
};