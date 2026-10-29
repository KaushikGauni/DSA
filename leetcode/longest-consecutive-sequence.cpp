// Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// Accepted 2026-08-10 | Runtime 92 ms | Memory 89 MB

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(), nums.end());
        
        int res = 0,streak = 0;
        
        for(int i : hs){
            if(!hs.count(i-1)){
                streak = 1;
                while(hs.count(i+1)){
                    streak++;
                    i++;
                }
            }
            res = max(res, streak);
        }

        return res;
    }
};