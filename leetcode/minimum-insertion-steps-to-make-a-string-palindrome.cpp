// Minimum Insertion Steps to Make a String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Accepted 2026-07-24 | Runtime 24 ms | Memory 31.5 MB

class Solution {
public:

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j] = 1;
                }
                else if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        int res = dp[0][n-1];
        return n - res;
    }
};