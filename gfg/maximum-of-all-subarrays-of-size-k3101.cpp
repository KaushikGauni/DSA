// K Sized Subarray Maximum (Medium)
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// Correct 2026-09-18 10:02:16 | C++

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        vector<int> res;
        
        for(int i=0;i<arr.size();i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1){
                res.push_back(arr[dq.front()]);
            }
        }
        
        return res;
    }
};