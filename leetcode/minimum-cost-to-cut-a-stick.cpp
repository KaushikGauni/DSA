// Minimum Cost to Cut a Stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Accepted 2026-07-27 | Runtime 42 ms | Memory 14 MB

class Solution {
public:

    int recurse(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            mini = min(mini, recurse(cuts,i,k-1,dp) + recurse(cuts,k+1,j,dp) + (cuts[j+1]-cuts[i-1]));
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return recurse(cuts,1,m-2,dp);
    }
};