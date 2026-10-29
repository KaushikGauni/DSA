// Copy Set Bits in Range (Easy)
// https://www.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1
// Correct 2026-09-04 13:31:39 | C++

class Solution {
  public:
    int setSetBit(int x, int y, int l, int r) {
        // code here
        int res = 0;
        for(int i=l;i<=r;i++){
            int bit = (y >> (i-1)) & 1;
            if(bit){
                x |= (1 << (i-1));
            }
        }
        
        return x;
    }
};