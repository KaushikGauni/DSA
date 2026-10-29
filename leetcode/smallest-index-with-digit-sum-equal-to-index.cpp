// Smallest Index With Digit Sum Equal to Index
// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
// Accepted 2026-10-21 | Runtime 0 ms | Memory 31.1 MB

class Solution {
public:

    int stum(int n){
        int res = 0;
        while(n>0){
            res += (n % 10);
            n = n/10;
        }
        return res;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(stum(nums[i]) == i) return i;
        }

        return -1;
    }
};