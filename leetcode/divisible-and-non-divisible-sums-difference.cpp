// Divisible and Non-divisible Sums Difference
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
// Accepted 2025-11-03 | Runtime 0 ms | Memory 8.3 MB

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                num1+=i;
            }
            else{
                num2+=i;
            }
        }

        return num1-num2;
    }
};