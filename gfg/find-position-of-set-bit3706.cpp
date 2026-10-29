// Position of Only Set Bit (Easy)
// https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
// Correct 2026-09-03 16:32:08 | C++

class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n<=0 || (n&(n-1))!=0){
            return -1;
        }
        return log2(n)+1;
    }
};