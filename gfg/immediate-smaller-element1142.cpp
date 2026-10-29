// Next Smaller Element (Medium)
// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
// Correct 2026-09-10 09:50:21 | C++

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};