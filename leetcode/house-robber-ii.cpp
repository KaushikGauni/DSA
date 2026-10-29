// House Robber II
// https://leetcode.com/problems/house-robber-ii/
// Accepted 2026-09-23 | Runtime 0 ms | Memory 10.1 MB

class Solution {
public:
    int robber(int start, int end, vector<int> &nums){
        int prev1 = 0, prev2 = 0;
        for(int i= start ;i<=end;i++){
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int case1 = robber(0,n-2,nums);
        int case2 = robber(1,n-1,nums);
        return max(case1, case2);
    }
};