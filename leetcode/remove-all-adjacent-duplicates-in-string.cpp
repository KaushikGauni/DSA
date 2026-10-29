// Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Accepted 2026-07-01 | Runtime 0 ms | Memory 14.1 MB

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s){
            if(!st.empty() && c==st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        string res;

        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};