// Palindrome Number
// https://leetcode.com/problems/palindrome-number/
// Accepted 2025-12-10 | Runtime 3 ms | Memory 8.5 MB

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        int r = 0;
        while(x>r){
            r =r *10 + x%10;
            x = x/10;
        }
        return x==r || x==r/10;
    }
};