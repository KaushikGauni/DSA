// Rotate String
// https://leetcode.com/problems/rotate-string/
// Accepted 2026-06-21 | Runtime 2 ms | Memory 9.3 MB

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }

        for(int i=0;i<s.size();i++){
            string temp = s.substr(i) + s.substr(0,i);
            if(temp==goal){
                return true;
            }
        }

        return false;
    }
};