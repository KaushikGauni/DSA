// k Largest Elements (Medium)
// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
// Correct 2026-09-16 14:44:00 | C++

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : arr){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res(k);
        int i = k-1;
        while(!pq.empty()){
            res[i--] = pq.top();
            pq.pop();
        }
        
        return res;
    }
};