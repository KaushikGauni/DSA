// Online Stock Span
// https://leetcode.com/problems/online-stock-span/
// Accepted 2026-06-30 | Runtime 9 ms | Memory 92 MB

class StockSpanner {
public:
    stack<pair<int, int>> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int k = 1;
        while(!prices.empty() && prices.top().first <= price){
            k += prices.top().second;
            prices.pop();
        }
        prices.push({price,k});
        return k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */