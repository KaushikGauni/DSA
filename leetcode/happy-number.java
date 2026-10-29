// Happy Number
// https://leetcode.com/problems/happy-number/
// Accepted 2023-07-15 | Runtime 1 ms | Memory 39.9 MB

class Solution {
    public boolean isHappy(int n) {
        int x = n, y = n;
        while(x>1){
            x = func(x);
            if(x==1) return true;
            y = func(func(y));
            if(y==1) return true;
            if(x==y) return false;
        }
        return true;
    }

    public int func(int n){
        int x = n;
        int sum = 0;
        while(x>0){
            sum += (x%10) * (x%10);
            x = x/10;
        }

        return sum;
    }
}