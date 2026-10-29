// Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Accepted 2026-09-28 | Runtime 3 ms | Memory 10.5 MB

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for(char c : s){
            if(c=='('){
                st.push(curr);
                curr = "";
            }
            else if(c==')'){
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else{
                curr += c;
            }
        }

        return curr;
    }
};