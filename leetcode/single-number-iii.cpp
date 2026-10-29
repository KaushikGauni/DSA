// Single Number III
// https://leetcode.com/problems/single-number-iii/
// Accepted 2026-06-27 | Runtime 0 ms | Memory 14 MB

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;
        for(int i : nums){
            x ^= i;
        }
        x = x & -x;

        int a = 0, b = 0;

        for(int i : nums){
            if((unsigned int)i & x){
                a ^= i;
            }
            else{
                b ^= i;
            }
        }

        return {a,b};
    }
};