// Postfix Evaluation (Medium)
// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
// Correct 2026-09-02 14:42:04 | C++

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(string s : arr){
            if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(s=="+"){
                    st.push(a+b);
                }
                else if(s=="-"){
                    st.push(a-b);
                }
                else if(s=="*"){
                    st.push(a*b);
                }
                else if(s=="/"){
                    st.push(floor((double)a/b));
                }
                else if(s=="^"){
                    st.push(pow(a,b));
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};