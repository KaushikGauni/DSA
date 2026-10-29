// Count Palindromic Subsequences (Medium)
// https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1
// Correct 2026-10-03 19:02:51 | C++

class Solution {
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
        vector<int> dp(s.size(),1);
        
        for(int i=s.size()-2;i>=0;i--){
            int diagonal = 0;
            for(int j=i+1;j<s.size();j++){
                int old = dp[j];
                
                if(s[i] == s[j]){
                    dp[j] = 1 + dp[j] + dp[j-1];
                }
                else{
                    dp[j] = dp[j] + dp[j-1] - diagonal;
                }
                diagonal = old;
            }
        }
        
        return dp[s.size()-1];
        
    }
};