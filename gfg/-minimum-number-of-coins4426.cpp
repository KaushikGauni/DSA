// Minimum Coins of 1, 2, 5 and 10 (Easy)
// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
// Correct 2026-10-07 10:45:32 | C++

class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> coins = {1,2,5,10};
        
        int i = 3;
        int count = 0;
        while(i>=0){
            if(coins[i] <= n){
                n -= coins[i];
                count++;
                if(n==0) return count;
            }
            else{
                i--;
            }
        }
        
        return count;
    }
};