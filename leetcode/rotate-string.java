// Rotate String
// https://leetcode.com/problems/rotate-string/
// Accepted 2025-08-29 | Runtime 0 ms | Memory 41.6 MB

class Solution {
    public boolean rotateString(String s, String goal) {
        boolean a = (s+s).contains(goal);
        boolean b = s.length()==goal.length();
        return a==b;
    }
}