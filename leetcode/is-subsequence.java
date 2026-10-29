// Is Subsequence
// https://leetcode.com/problems/is-subsequence/
// Accepted 2023-06-24 | Runtime 2 ms | Memory 40.7 MB

class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while(i<s.length() && j<t.length()){
            if(s.charAt(i)==t.charAt(j)){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==s.length()){
            return true;
        }
        return false;
    }
}