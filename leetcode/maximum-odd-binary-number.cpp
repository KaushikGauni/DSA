// Maximum Odd Binary Number
// https://leetcode.com/problems/maximum-odd-binary-number/
// Accepted 2025-10-09 | Runtime 3 ms | Memory 11.1 MB

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(), s.rend());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);
            }
        }
        return s;
    }
};