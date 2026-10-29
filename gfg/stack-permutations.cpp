// Validate Stack Operations (Medium)
// https://www.geeksforgeeks.org/problems/stack-permutations/1
// Correct 2026-09-09 11:43:22 | C++

class Solution {
  public:
    bool validateOp(vector<int>& a, vector<int>& b) {
        // code here
        stack<int> st;
        int j = 0;
        for(int i=0;i<a.size();i++){
            st.push(a[i]);
            while(!st.empty() && st.top()==b[j]){
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
};