// Jump Game II
// https://leetcode.com/problems/jump-game-ii/
// Accepted 2026-06-30 | Runtime 0 ms | Memory 20.6 MB

class Solution {
public:

    int jump(vector<int>& nums) {
        int currEnd = 0, farthest = 0, jumps = 0;
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest, i+nums[i]);
            if(i==currEnd){
                currEnd = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};