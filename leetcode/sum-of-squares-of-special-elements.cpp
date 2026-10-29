// Sum of Squares of Special Elements 
// https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Accepted 2026-10-11 | Runtime 1 ms | Memory 40.1 MB

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                res += nums[i-1] * nums[i-1];
            }
        }

        return res;
    }
};