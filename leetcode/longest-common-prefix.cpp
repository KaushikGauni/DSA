// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Accepted 2026-09-22 | Runtime 0 ms | Memory 12.1 MB

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(pre)!=0){
                pre = pre.substr(0,pre.size()-1);
                if(pre==""){
                    return pre;
                }
            }
        }

        return pre;
    }
};