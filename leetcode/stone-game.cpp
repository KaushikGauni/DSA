// Stone Game
// https://leetcode.com/problems/stone-game/
// Accepted 2026-08-02 | Runtime 11 ms | Memory 19.7 MB

class Solution {
public:

    int recurse(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int takeLeft = nums[i] - recurse(i+1,j,nums,dp);
        int takeRight = nums[j] - recurse(i,j-1,nums,dp);

        return dp[i][j] = max(takeRight, takeLeft);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recurse(0,n-1,piles,dp) >= 0;
    }
};