// Power of 2 (Basic)
// https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Correct 2026-09-03 16:26:36 | C++

class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        return n>0 && (n&(n-1))==0;
    }
};