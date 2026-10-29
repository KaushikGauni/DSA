// Smallest Positive Missing (Medium)
// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
// Correct 2026-09-18 10:19:33 | C++

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i : arr){
            if(i>0){
                pq.push(i);
            }
        }
        
        int expected = 1;
        
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            
            if(x==expected-1){
                continue;
            }
            
            if(x!=expected){
                return expected;
            }
            
            expected++;
        }
        
        return expected;
    }
};