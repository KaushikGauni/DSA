// Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// Accepted 2026-09-18 | Runtime 62 ms | Memory 111.3 MB

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hs;
        for(int i : nums){
            if(hs.count(i)){
                return true;
            }
            hs.insert(i);
        }

        return false;
    }
};