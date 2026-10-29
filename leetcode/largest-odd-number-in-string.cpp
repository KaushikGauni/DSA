// Largest Odd Number in String
// https://leetcode.com/problems/largest-odd-number-in-string/
// Accepted 2026-06-16 | Runtime 0 ms | Memory 18 MB

class Solution {
public:
    string largestOddNumber(string num) {
        int i = 0;
        for(i=num.size()-1;i>=0;i--){
            if(((num[i]-'0')%2)!=0){
                break;
            }
        }
        num = num.substr(0,i+1);

        return num;
    }
};