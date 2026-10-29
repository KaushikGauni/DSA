// Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Accepted 2026-09-28 | Runtime 3 ms | Memory 71.6 MB

class Solution {
public:

    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int l = 0, r= 0, sum = 0, res = 0;
        for(r=0;r<nums.size();r++){
            sum += nums[r];

            while(sum > k){
                sum -= nums[l];
                l++;
            }

            res += r - l + 1;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int &i : nums){
            if(i%2!=0){
                i=1;
            }
            else{
                i = 0;
            }
        }
        return atmost(nums,k) - atmost(nums,k-1);
    }
};