// Sum Except First and Last (Basic)
// https://www.geeksforgeeks.org/problems/max-length-chain/1
// Correct 2026-10-04 11:57:32 | C++

class Solution {
  public:
    int sumExceptFirstLast(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n<=2) return 0;
        
        return accumulate(arr.begin()+1, arr.end()-1,0);
    }
};