// Subarrays Distinct Element Sum of Squares I
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Accepted 2026-10-22 | Runtime 38 ms | Memory 36.4 MB

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                res += s.size() * s.size();
            }
        }

        return res;
    }
};