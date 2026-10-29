// Removing Minimum and Maximum From Array
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Accepted 2026-08-31 | Runtime 4 ms | Memory 92.1 MB

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = -1, maxIdx = -1, minEle = INT_MAX, maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<minEle){
                minEle = nums[i];
                minIdx = i;
            }
            if(nums[i]>maxEle){
                maxEle = nums[i];
                maxIdx = i;
            }
        }

        int left = max(maxIdx,minIdx) + 1;
        int right = n - min(maxIdx,minIdx);
        int mixed1 = (n-maxIdx) + (minIdx+1);
        int mixed2 = (n-minIdx) + (maxIdx+1);

        return min({left, right, mixed1, mixed2});
    }
};