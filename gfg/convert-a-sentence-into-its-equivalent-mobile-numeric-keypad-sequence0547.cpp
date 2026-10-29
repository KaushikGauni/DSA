// Sentence to Mobile Numeric Sequence (Easy)
// https://www.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1
// Correct 2026-09-22 11:51:52 | C++

class Solution {
  public:
    string printSequence(string &s) {
        // code here
        string key[] = {
                    "2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"
                };
        string res = "";
        for(char i : s){
            if(i==' '){
                res += "0";
                continue;
            }
            res += key[i-'A'];
        }
        return res;
    }
};