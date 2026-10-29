// Next Greater Element (Medium)
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Correct 2026-09-09 12:15:51 | C++

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int> res(arr.size());
        stack<int> st;
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            
            res[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};