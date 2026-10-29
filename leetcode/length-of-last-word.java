// Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
// Accepted 2025-01-26 | Runtime 1 ms | Memory 41.8 MB

class Solution {
    public int lengthOfLastWord(String s) {
        int res = 0;
        for(char c : s.strip().toCharArray()){
            if(c==' '){
                res = 0;
            }
            else{
                res++;
            }
        }
        return res;
    }
}