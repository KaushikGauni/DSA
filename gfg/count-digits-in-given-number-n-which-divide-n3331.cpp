// Digits in N that Divide it (Medium)
// https://www.geeksforgeeks.org/problems/count-digits-in-given-number-n-which-divide-n3331/1
// Correct 2026-09-27 10:17:39 | C++

class Solution {
  public:
    int divisibleByDigits(string& s) {
        // code here
        int rem = 0;
        for(char c : s){
            rem = (rem * 10 + (c-'0')) % 2520;
        }
        
        int count = 0;
        
        for(char c : s){
            int d = c-'0';
            if(d!=0 && rem%d==0){
                count++;
            }
        }
        
        return count;
    }
};
