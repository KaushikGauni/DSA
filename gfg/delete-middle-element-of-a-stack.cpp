// Delete Mid of Stack (Easy)
// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// Correct 2026-09-09 09:49:09 | C++

class Solution {
  public:
  
    void solve(stack<int>& s, int curr, int mid){
        if(curr==mid){
            s.pop();
            return;
        }
        int x = s.top();
        s.pop();
        solve(s,curr+1,mid);
        s.push(x);
    }
  
    void deleteMid(stack<int>& s) {
        // code here
        int mid = (s.size() / 2) + 1;
        solve(s,1,mid);
    }
};