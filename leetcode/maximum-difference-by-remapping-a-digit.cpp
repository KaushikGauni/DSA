// Maximum Difference by Remapping a Digit
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
// Accepted 2025-10-09 | Runtime 2 ms | Memory 8.2 MB

class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);
        char maxdig = 0,mindig = 0;
        for(char c : s1){
            if(c!='9'){
                maxdig = c;
                break;
            }
        }
        for(char c : s2){
            if(c!='0'){
                mindig = c;
                break;
            }
        }
        for(char &ch : s1){
            if(ch==maxdig){
                ch = '9';
            }
        }
        for(char &ch : s2){
            if(ch==mindig){
                ch = '0';
            }
        }
        return stoi(s1)-stoi(s2);
    }
};