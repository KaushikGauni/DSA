// Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// Accepted 2025-11-28 | Runtime 0 ms | Memory 23.9 MB

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i=j;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};