// Remove K Digits
// https://leetcode.com/problems/remove-k-digits/
// Accepted 2026-06-28 | Runtime 5 ms | Memory 11.7 MB

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num){
            while(!st.empty() && st.top() > c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        int i = 0;

        while(res[i]=='0' && i<res.size()){
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};