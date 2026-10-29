// Coin Change II
// https://leetcode.com/problems/coin-change-ii/
// Accepted 2026-07-23 | Runtime 3 ms | Memory 10.1 MB

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount+1,0);
        dp[0] = 1;
        for(int coin : coins){
            for(int i=coin;i<=amount;i++){
                dp[i] += dp[i-coin];
            }
        }

        return dp[amount];
    }
};