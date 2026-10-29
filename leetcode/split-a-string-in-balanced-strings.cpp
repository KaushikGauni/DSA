// Split a String in Balanced Strings
// https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Accepted 2025-10-09 | Runtime 0 ms | Memory 8.2 MB

class Solution {
public:
    int balancedStringSplit(string s) {
        int rcount =0, count =0;
        for(char c : s){
            if(c=='R'){
                rcount++;
            }
            else if(c=='L'){
                rcount--;
            }
            if(rcount==0){
                count++;
            }
        }

        return count;
    }
};