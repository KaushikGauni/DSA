// Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/
// Accepted 2025-08-10 | Runtime 0 ms | Memory 41.9 MB

class MyQueue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();
    public MyQueue() {
        
    }
    
    public void push(int x) {
        s1.push(x);
    }
    
    public int pop() {
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        int res = s2.pop();
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
        return res;
    }
    
    public int peek() {
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        int res = s2.peek();
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
        return res;
    }
    
    public boolean empty() {
        return s1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */