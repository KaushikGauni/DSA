// Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
// Accepted 2026-09-20 | Runtime 0 ms | Memory 17.7 MB

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for(int i=1;i<nums.size(); i++){
            int x = nums[i];
            int prevMax = maxProd;
            int prevMin = minProd;

            maxProd = max({x, x * prevMax, x * prevMin});
            minProd = min({x, x * prevMax, x * prevMin});
            ans = max(ans, maxProd);
        }

        return ans;
    }
};