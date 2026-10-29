// Coin Change (Minimum Coins) (Medium)
// https://www.geeksforgeeks.org/problems/number-of-coins1824/1
// Correct 2026-09-27 14:14:37 | C++

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        
        vector<int> dp(sum+1,sum+1);
        dp[0] = 0;
        for(int coin : coins){
            for(int i=coin;i<=sum;i++){
                dp[i] = min(dp[i],1+dp[i-coin]);
            }
        }
        
        return dp[sum] == sum+1 ? -1 : dp[sum];
        
    }
};