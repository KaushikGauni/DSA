// Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/
// Accepted 2026-07-25 | Runtime 15 ms | Memory 12.7 MB

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> parent(n);
        int large = 0, maxInd = 0;
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i]>large){
                large = dp[i];
                maxInd = i;
            }
        }

        vector<int> res;

        while(parent[maxInd]!=maxInd){
            res.push_back(nums[maxInd]);
            maxInd = parent[maxInd];
        }
        res.push_back(nums[maxInd]);

        reverse(res.begin(), res.end());

        return res;
    }
};