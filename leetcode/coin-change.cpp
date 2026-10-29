// Coin Change
// https://leetcode.com/problems/coin-change/
// Accepted 2026-09-23 | Runtime 15 ms | Memory 18 MB

class Solution {
public:
    int recurse(vector<int>& coins, int i, int amount){
        if(amount == 0){
            return 0;
        }
        if(i < 0){
            return INT_MAX;
        }

        int nottake = recurse(coins,i-1,amount);

        int take = INT_MAX;

        if(coins[i] <= amount){
            int res = recurse(coins,i,amount - coins[i]);
            if(res != INT_MAX){
                take = 1 + res;
            }
        }

        return min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i : coins){
            for(int j=i;j<=amount;j++){
                dp[j] = min(dp[j], 1 + dp[j-i]);
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};