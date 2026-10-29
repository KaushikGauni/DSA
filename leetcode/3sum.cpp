// 3Sum
// https://leetcode.com/problems/3sum/
// Accepted 2026-09-22 | Runtime 43 ms | Memory 28.9 MB

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1, right = n-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return res;
    }
};