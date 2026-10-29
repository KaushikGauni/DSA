// Egg Dropping Puzzle (Medium)
// https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// Correct 2026-10-04 11:17:32 | C++

class Solution {
  public:
    int eggDrop(int n, int k) {
        // code here
        vector<int> dp(n+1,0);
        
        int ans = 0;
        
        while(dp[n] < k){
            ans++;
            
            for(int i = n;i>=1;i--){
                dp[i] = 1 + dp[i] + dp[i-1];
            }
        }
        
        return ans;
    }
};