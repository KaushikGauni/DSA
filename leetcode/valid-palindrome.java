// Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// Accepted 2025-08-10 | Runtime 2 ms | Memory 42.9 MB

class Solution {
    public boolean isPalindrome(String s) {
        int i=0, j=s.length()-1;
        while(i<j){
            while((i<j) && !Character.isLetterOrDigit(s.charAt(i))){
                i++;
            }
            while((i<j) && !Character.isLetterOrDigit(s.charAt(j))){
                j--;
            }
            if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
}