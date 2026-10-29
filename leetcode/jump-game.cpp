// Jump Game
// https://leetcode.com/problems/jump-game/
// Accepted 2026-09-23 | Runtime 3 ms | Memory 52.2 MB

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i=0;i<nums.size();i++){
            if(reachable < i){
                return false;
            }
            reachable = max(reachable, i + nums[i]);
        }

        return true;
    }
};