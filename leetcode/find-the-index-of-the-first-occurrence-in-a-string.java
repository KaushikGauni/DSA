// Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Accepted 2023-06-24 | Runtime 0 ms | Memory 40.8 MB

class Solution {
    public int strStr(String haystack, String needle) {
        int k = needle.length();
        int n = haystack.length();
        for(int i=0;i<n-k+1;i++){
            String sub = haystack.substring(i,i+k);
            if(sub.equals(needle)){
                return i;
            }
        }
        return -1;
    }
}