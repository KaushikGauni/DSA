// Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/
// Accepted 2025-10-08 | Runtime 0 ms | Memory 8.1 MB

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i=0,j=s.length()-1;
        while(i<s.length()){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
            i++;
        }
        return stoi(s);
    }
};