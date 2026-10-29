// Reverse String
// https://leetcode.com/problems/reverse-string/
// Accepted 2022-09-18 | Runtime 1 ms | Memory 54.8 MB

import java.util.*;
class Solution {
    public void reverseString(char[] s) {
        int i = 0;
        int j = s.length-1;
        char c;
        while(i<j){
            c = s[i];
            s[i++] = s[j];
            s[j--] = c;
        }
    }
}