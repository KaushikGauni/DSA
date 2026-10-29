// Min Cost to Connect Ropes (Medium)
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Correct 2026-09-17 14:18:37 | C++

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : arr){
            pq.push(i);
        }
        
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a+b;
            pq.push(a+b);
        }
        
        return sum;
    }
};