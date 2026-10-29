// Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// Accepted 2026-09-19 | Runtime 0 ms | Memory 9.9 MB

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};