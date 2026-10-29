// Maximize The Cut Segments (Medium)
// https://www.geeksforgeeks.org/problems/cutted-segments1642/1
// Correct 2026-10-04 18:08:28 | C++

class Solution {
  public:
  
    int recurse(int n, int x, int y, int z,vector<int> &dp){
        if(n==0) return 0;
        
        if(n<0) return INT_MIN;
        
        if(dp[n]!=-1) return dp[n];
        
        int a = recurse(n-x,x,y,z,dp);
        int b = recurse(n-y,x,y,z,dp);
        int c = recurse(n-z,x,y,z,dp);
        
        int ans = max({a,b,c});
        
        if(ans == INT_MIN) return dp[n] = INT_MIN;
        
        return dp[n] = 1 + ans;
    }
  
    int maximizeCuts(int n, int x, int y, int z) {
        // code here
        vector<int> dp(n+1,-1);
        int ans = recurse(n,x,y,z,dp);
        
        return ans < 0 ? 0 : ans;
        
    }
};