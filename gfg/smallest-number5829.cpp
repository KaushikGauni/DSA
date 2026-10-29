// Smallest with d Dgitis and s Sum (Medium)
// https://www.geeksforgeeks.org/problems/smallest-number5829/1
// Correct 2026-08-31 12:46:29 | C++

class Solution {
  public:
  
  
    string smallestNumber(int s, int d) {
        // code here
        
        if(s<1 || s>d*9){
            return "-1";
        }
        
        vector<int> digits(d,0);
        digits[0] = 1;
        s--;
        
        for(int i=d-1;i>=0 && s>0;i--){
            int add = min(9,s);
            digits[i] += add;
            s -= add;
        }
        
        
        if(s>0){
            return "-1";
        }
        
        string res = "";
        
        for(int i=0;i<d;i++){
            res += to_string(digits[i]);
        }
        
        return res;
    }
};