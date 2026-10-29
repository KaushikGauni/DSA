// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Accepted 2025-08-10 | Runtime 1 ms | Memory 61.9 MB

class Solution {
    public int maxProfit(int[] prices) {
        int max = 0, min = Integer.MAX_VALUE;
        for(int i : prices){
           min = Math.min(min,i); 
           max = Math.max(max,i-min);  
        }

        return max;
    }
}