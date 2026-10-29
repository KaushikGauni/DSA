// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// Accepted 2026-01-09 | Runtime 68 ms | Memory 87.9 MB

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hs;
        for(int i : nums){
            if(hs.count(i)){
                return i;
            }
            hs.insert(i);
        }
        return -1;
    }
};