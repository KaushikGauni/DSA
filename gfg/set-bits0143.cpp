// Count Set Bits (Easy)
// https://www.geeksforgeeks.org/problems/set-bits0143/1
// Correct 2026-09-03 16:15:50 | C++

class Solution {
  public:
    int setBits(int n) {
        // Code here
        int count = 0;
        while(n>0){
            count += n&1;
            n = n >> 1;
        }
        return count;
    }
};