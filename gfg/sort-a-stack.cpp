// Sort Stack (Medium)
// https://www.geeksforgeeks.org/problems/sort-a-stack/1
// Correct 2026-09-09 11:52:38 | C++

class Solution {
  public:
  
  
    void sortInserted(stack<int> &st, int top){
        if(st.empty() || st.top()<=top){
            st.push(top);
            return;
        }
        
        int x = st.top();
        st.pop();
        
        sortInserted(st,top);
        
        st.push(x);
        
    }
  
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        
        int top = st.top();
        st.pop();
        
        sortStack(st);
        
        sortInserted(st,top);
    }
};
