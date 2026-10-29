// Minimum Time to Type Word Using Special Typewriter
// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
// Accepted 2025-10-09 | Runtime 0 ms | Memory 8.3 MB

class Solution {
public:
    int minTimeToType(string word) {
        int pointer = 'a', seconds = word.size();
        for(char c : word){
            seconds += (min(abs(c-pointer),26-abs(c-pointer)));
            pointer = c;
        }
        return seconds;
    }
};