// Valid Substring (Medium)
// https://www.geeksforgeeks.org/problems/valid-substring0624/1
// Correct 2026-09-09 10:35:21 | C++

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int open = 0, close = 0, maxLen = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(open==close){
                maxLen = max(maxLen, 2 * open);
            }
            
            else if(close > open){
                open = close = 0;
            }
        }
        
        open = 0, close = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(open==close){
                maxLen = max(maxLen, 2 * open);
            }
            
            else if(open > close){
                open = close = 0;
            }
        }
        
        return maxLen;
    }
};