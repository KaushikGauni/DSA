// Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Accepted 2026-07-25 | Runtime 0 ms | Memory 16.3 MB

class Solution {
public:

    int recurse(int i, int buy, vector<int>& prices,vector<vector<int>> &dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy){
            int Buy = -prices[i] + recurse(i+1,0,prices, dp);
            int skip = recurse(i+1,1,prices, dp);

            profit = max(Buy,skip);
        }
        else{
            int Sell = prices[i] + recurse(i+2,1,prices, dp);
            int skip = recurse(i+1,0,prices, dp);

            profit = max(Sell,skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return recurse(0,1,prices,dp);
    }
};