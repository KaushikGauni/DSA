// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
// Accepted 2026-06-22 | Runtime 1 ms | Memory 9.2 MB

class Solution {
public:
    int myAtoi(string s) {
        long long total = 0;
        int i = 0;
        int negative = 1;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                negative = -1;
            }
            i++;
        }
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            total = total * 10 + (s[i]-'0');
            if(total * negative > INT_MAX) return INT_MAX;
            if(total * negative < INT_MIN) return INT_MIN;
            i++;
        }

        return total*negative;
    }
};