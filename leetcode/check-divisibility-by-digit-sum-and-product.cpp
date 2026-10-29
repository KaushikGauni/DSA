// Check Divisibility by Digit Sum and Product
// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
// Accepted 2026-08-22 | Runtime 0 ms | Memory 7.7 MB

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n, sum = 0, prod = 1;
        while(temp!=0){
            int rem = temp%10;
            sum += rem;
            prod *= rem;
            temp /=10;
        }
        return (n % (sum+prod))==0;
    }
};