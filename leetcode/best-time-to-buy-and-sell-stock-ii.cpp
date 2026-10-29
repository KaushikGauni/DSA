// Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Accepted 2026-07-24 | Runtime 0 ms | Memory 19.9 MB

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy = 0;
        int aheadNotBuy = 0;
        int curr = 0;
        for(int i=n-1;i>=0;i--){
            int currBuy = max(-prices[i]+aheadNotBuy, aheadBuy);
            int currNotBuy = max(prices[i]+aheadBuy, aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};