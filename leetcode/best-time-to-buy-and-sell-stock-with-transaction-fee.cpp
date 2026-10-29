// Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Accepted 2026-07-25 | Runtime 12 ms | Memory 63.5 MB

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];
        int cash = 0;
        for(int i=1;i<prices.size();i++){
            hold = max(hold,cash-prices[i]);
            cash = max(cash,hold+prices[i]-fee);
        }

        return cash;
    }
};