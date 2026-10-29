// Replace Consecutive Two Same with One (Easy)
// https://www.geeksforgeeks.org/problems/consecutive-elements2306/1
// Correct 2026-09-19 11:49:57 | C++

class Solution {
  public:
    string removeDuplicates(string& s) {
        // code here.
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==s[i]){
                continue;
            }
            st.push(s[i]);
        }
        string res(st.size(),'a');
        for(int i=res.size()-1;i>=0;i--){
            res[i] = st.top();
            st.pop();
        }
        
        return res;
    }
};