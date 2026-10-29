// Longest Common Substring (Medium)
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Correct 2026-10-03 14:54:55 | C++

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> dp(m+1,0);
        
        int ans = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + dp[j-1];
                    ans = max(ans, dp[j]);
                }
                else{
                    dp[j] = 0;
                }
            }
        }
        
        
        return ans;
    }
};