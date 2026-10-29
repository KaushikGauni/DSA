// Kth Largest in Stream (Medium)
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
// Correct 2026-09-16 15:56:03 | C++

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int> res(arr.size());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i =0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size() < k){
                res[i] = -1;
                continue;
            }
            if(pq.size() > k){
                pq.pop();
            }
            res[i] = pq.top();
        }
        
        return res;
    }
};