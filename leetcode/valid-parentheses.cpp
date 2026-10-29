// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Accepted 2026-09-19 | Runtime 0 ms | Memory 9.3 MB

class Solution {
public:
    unordered_map<char,char> hm;
    bool isValid(string s) {
        hm['}'] = '{';
        hm[')'] = '(';
        hm[']'] = '[';
        stack<char> st;
        for(char c : s){
            if(st.empty() || c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(hm[c] != st.top()){
                return false;
            }
            else{
                st.pop();
            }
        }

        return st.empty();
    }
};