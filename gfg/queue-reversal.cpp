// Queue Reversal (Easy)
// https://www.geeksforgeeks.org/problems/queue-reversal/1
// Correct 2026-09-09 09:38:33 | C++

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> st;
        while(q.size()){
            st.push(q.front());
            q.pop();
        }
        
        while(st.size()){
            q.push(st.top());
            st.pop();
        }
    }
};