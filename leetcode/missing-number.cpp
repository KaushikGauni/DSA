// Missing Number
// https://leetcode.com/problems/missing-number/
// Accepted 2025-11-24 | Runtime 0 ms | Memory 21.6 MB

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        return (n*(n+1))/2 - sum;
    }
};