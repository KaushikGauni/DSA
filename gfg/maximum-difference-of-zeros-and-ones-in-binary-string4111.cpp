// Substring with Max Zero-One Diff (Medium)
// https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
// Correct 2026-09-23 10:37:21 | C++

class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int res = INT_MIN, curr = 0;
        for(char c : s){
            if(c=='0'){
                curr++;
            }
            else{
                curr--;
            }
            res = max(res,curr);
            if(curr < 0){
                curr = 0;
            }
        }
        
        return res;
    }
};