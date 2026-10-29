// Reverse first K of a Queue (Easy)
// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Correct 2026-09-02 14:29:20 | C++

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k>q.size()){
            return q;
        }
        stack<int> s;
        for(int i=0;i<k;i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        int rem = q.size() - k;
        
        for(int i=0;i<rem;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
        
    }
};