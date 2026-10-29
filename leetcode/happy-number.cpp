// Happy Number
// https://leetcode.com/problems/happy-number/
// Accepted 2025-12-26 | Runtime 0 ms | Memory 7.7 MB

class Solution {
public:
    int squared(int n){
        int r = 0;
        while(n){
            r = r + (n%10)*(n%10);
            n = n/10;
        }
        return r;
    }
    bool isHappy(int n) {
        int x = n, y=n;
        do{
            x = squared(x);
            y = squared(squared(y));
        }while(x!=y);

        return x==1;
    }
};