// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Accepted 2025-08-09 | Runtime 4 ms | Memory 41.8 MB

class Solution {
    public boolean isValid(String s) {
        Stack <Character> st = new Stack<Character>();
        for(char c : s.toCharArray()){
            if(st.isEmpty() && (c=='(' || c=='[' || c=='{')){
                st.push(c);
            }
            else if(st.isEmpty() && (c==']' || c==')' || c=='}')){
                return false;
            }
            else if(st.peek()=='(' && c==')'){
                st.pop();
            }
            else if(st.peek()=='[' && c==']'){
                st.pop();
            }
            else if(st.peek()=='{' && c=='}'){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        return st.isEmpty();
    }
}