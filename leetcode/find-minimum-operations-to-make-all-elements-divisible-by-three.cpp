// Find Minimum Operations to Make All Elements Divisible by Three
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Accepted 2026-08-20 | Runtime 0 ms | Memory 23.2 MB

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(int i : nums){
            res += (i % 3)!=0;
        }
        return res;
    }
};