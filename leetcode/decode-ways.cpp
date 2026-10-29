// Decode Ways
// https://leetcode.com/problems/decode-ways/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 8.5 MB

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i] += dp[i-1];
            }

            int prev1 = s[i-1] - '0';
            int prev2 = s[i-2] - '0';
            int temp = prev2 * 10 + prev1;
            if(temp >=10 && temp<=26){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};