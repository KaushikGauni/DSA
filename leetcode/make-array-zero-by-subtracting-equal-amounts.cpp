// Make Array Zero by Subtracting Equal Amounts
// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
// Accepted 2025-10-09 | Runtime 3 ms | Memory 10.9 MB

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(int i : nums){
            if(i>0){
                s.insert(i);
            }
        }

        return s.size();
    }
};