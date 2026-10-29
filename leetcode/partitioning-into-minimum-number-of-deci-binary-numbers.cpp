// Partitioning Into Minimum Number Of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Accepted 2025-10-09 | Runtime 0 ms | Memory 16.5 MB

class Solution {
public:
    int minPartitions(string n) {
        int maxint = INT_MIN;
        for(char c : n){
            maxint = max(maxint,c-'0');
        }
        return maxint;
    }
};