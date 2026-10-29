// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Accepted 2026-09-19 | Runtime 0 ms | Memory 97.4 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            maxProfit = max(maxProfit, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }

        return maxProfit;
        
    }
};