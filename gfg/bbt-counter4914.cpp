// Balanced Binary Tree Counter (Easy)
// https://www.geeksforgeeks.org/problems/bbt-counter4914/1
// Correct 2026-09-15 11:10:02 | C++

class Solution {
  public:
    int countBT(int h) {
        const long long MOD = 1e+9;
        long long prev1 = 1, prev2 = 1;
        
        for(int i=2;i<=h;i++){
            long long temp = ((prev2 * prev2)%MOD + 2 * prev1 * prev2 % MOD) % MOD;
            prev1 = prev2;
            prev2 = temp;
        }
        
        return (int)prev2;
    }
};