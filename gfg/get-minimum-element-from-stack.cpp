// Get Min from Stack (Medium)
// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// Correct 2026-09-09 10:03:11 | C++

class SpecialStack {
  public:
    stack<long long> st;
    long long minVal;
    SpecialStack() {
        // Define Stack
        minVal = -1;
    }

    void push(int x) {
        // Add an element to the top of Stack
        if(st.empty()){
            st.push(x);
            minVal = x;
        }
        else if(x < minVal){
            st.push(2LL*x - minVal);
            minVal = x;
        }
        else{
            st.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.empty()){
            return;
        }
        long long top = st.top();
        st.pop();
        if(top < minVal){
            minVal = 2 * minVal - top;
        }
        
    }

    int peek() {
        // Returns top element of the Stack
        if(st.empty()){
            return -1;
        }
        long long top = st.top();
        return (int) (top < minVal ? minVal : top);
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st.empty()){
            return -1;
        }
        return minVal;
    }
};