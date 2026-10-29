// Minimum Number of Pushes to Type Word I
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Accepted 2026-07-31 | Runtime 0 ms | Memory 8.2 MB

class Solution {
public:
    int minimumPushes(string word) {
        int cost = 0;
        int n = word.size();
        int x = 0;
        for(int i=0;i<n;i++){
            cost += x / 8 + 1;
            x++;
        }

        return cost;
    }
};