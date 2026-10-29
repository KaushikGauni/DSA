// Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
// Accepted 2023-06-30 | Runtime 8 ms | Memory 44.1 MB

class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] a = s.split("\\s+");
        StringBuilder string = new StringBuilder();
        for(int i=a.length-1;i>=0;i--){
            string.append(a[i]+" ");
        }
        return string.toString().trim();
    }
}