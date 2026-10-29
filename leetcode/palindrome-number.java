// Palindrome Number
// https://leetcode.com/problems/palindrome-number/
// Accepted 2025-07-29 | Runtime 5 ms | Memory 44 MB

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int t = x,res=0;
        while(t!=0){
            res = res * 10 + t%10;
            t = t/10;
        }
        return x==res;
    }
}