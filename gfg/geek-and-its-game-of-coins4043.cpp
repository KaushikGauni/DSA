// Geek and Game of Coins (Medium)
// https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1
// Correct 2026-10-05 11:59:18 | C++

class Solution {
  public:
  
    int recurse(int n, int x, int y, vector<int> &dp){
        if(n<=0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        
        bool win = false;
        
        if(n>=1 && recurse(n-1,x,y,dp)==0){
            win = true;
        }
        if(n>=x && recurse(n-x,x,y,dp)==0){
            win = true;
        }
        if(n>=y && recurse(n-y,x,y,dp)==0){
            win = true;
        }
        return dp[n] = win;
    }
  
    int findWinner(int n, int x, int y) {
        // code here
        vector<int> dp(n+1,-1);
        return recurse(n,x,y,dp);
    }
};
