// Count Set Bits in 1 to n (Medium)
// https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
// Correct 2026-09-04 10:37:44 | C++

class Solution {
  public:
  
    int countSetBits(int n) {
        // code here
        long long res = 0;
        for(long long p = 1;p<=n;p<<=1){
            long long cycle = p << 1;
            long long full = ((long long)n+1) / cycle;
            long long rem = ((long long)n+1) % cycle;
            res += full * p + max(0LL,rem-p);
        }
        
        return res;
    }
};
