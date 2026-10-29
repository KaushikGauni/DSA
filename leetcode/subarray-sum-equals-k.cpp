// Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Accepted 2026-08-03 | Runtime 43 ms | Memory 45.4 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        hm[0] = 1;
        int prefix = 0;
        int res = 0;
        for(int i : nums){
            prefix += i;

            if(hm.count(prefix-k)){
                res += hm[prefix-k];
            }

            hm[prefix]++;
        }

        return res;
    }
};