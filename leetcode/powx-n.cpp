// Pow(x, n)
// https://leetcode.com/problems/powx-n/
// Accepted 2026-07-02 | Runtime 0 ms | Memory 8.7 MB

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }

        double ans = 1;

        while(N>0){
            if(N%2==1){
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
    }
};