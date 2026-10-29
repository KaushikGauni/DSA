// Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/
// Accepted 2026-06-26 | Runtime 0 ms | Memory 8 MB

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char c : s){
            if(c=='('){
                low++;
                high++;
            }
            else if(c==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }

            if(high<0){
                return false;
            }

            low = max(low,0);
        }

        return low==0;
    }
};