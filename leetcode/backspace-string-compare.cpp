// Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/
// Accepted 2025-11-25 | Runtime 0 ms | Memory 8.6 MB

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(char c : s){
            if(c=='#' && !s1.empty()){
                s1.pop();
            }
            else if(c!='#'){
                s1.push(c);
            }
        }
        
        for(char c : t){
            if(c=='#' && !s2.empty()){
                s2.pop();
            }
            else if(c!='#'){
                s2.push(c);
            }
        }

        return s1==s2;
    }
};