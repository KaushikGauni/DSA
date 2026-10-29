// Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// Accepted 2026-08-03 | Runtime 1 ms | Memory 37.2 MB

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        prefix.push_back(0);
        for(int i : nums){
            prefix.push_back(i + prefix.back());
        }
        for(int i=1;i<prefix.size();i++){
            if((prefix[i-1]-prefix[0])==(prefix[prefix.size()-1]-prefix[i])){
                return i-1;
            }
        }
        return -1;
    }
};