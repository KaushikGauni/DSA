// Minimum Total Price After Applying Discounts
// https://leetcode.com/problems/minimum-total-price-after-applying-discounts/
// Accepted 2026-08-12 | Runtime 59 ms | Memory 223.4 MB

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        int i = 0;
        double price = 0;
        for(i=0;i<discounts.size() && i<prices.size() ;i++){
            price += (prices[i] * (100-discounts[i])) / 100.0;
        }

        for(int j=i;j<prices.size();j++){
            price += prices[j];
        }

        return price;

        
    }
};