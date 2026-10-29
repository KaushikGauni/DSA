// Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Accepted 2026-09-28 | Runtime 0 ms | Memory 8.2 MB

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxDepth = 0;
        for(char c : s){
            if(c=='('){
                count++;
                maxDepth = max(maxDepth, count);
            }
            else if(c==')'){
                count--;
            }
        }

        return maxDepth;
    }
};