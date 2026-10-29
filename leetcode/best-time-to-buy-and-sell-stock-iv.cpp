// Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Accepted 2026-07-25 | Runtime 7 ms | Memory 18.1 MB

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=0;l<k;l++){
                    if(j){
                        int take = -prices[i] + dp[i+1][0][l];
                        int notake = dp[i+1][1][l];

                        dp[i][j][l] = max(take,notake);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][1][l+1];
                        int nosell = dp[i+1][0][l];

                        dp[i][j][l] = max(sell,nosell);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};