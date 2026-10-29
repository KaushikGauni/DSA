// Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array/
// Accepted 2026-08-03 | Runtime 0 ms | Memory 16 MB

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
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