// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Accepted 2023-08-22 | Runtime 6 ms | Memory 43.6 MB

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = 0;
        HashSet<Character> hs = new HashSet<>();
        int l = 0,j=0;
        for(int i=0;i<s.length();i++){
            if(!(hs.contains(s.charAt(i)))){
                hs.add(s.charAt(i));
                length = Math.max(length, i-j+1);
            }
            else{
                while(hs.contains(s.charAt(i))){
                    hs.remove(s.charAt(j));
                    j++;
                }
                hs.add(s.charAt(i));
            }
        }
        return length;
    }
}