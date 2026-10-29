// Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/
// Accepted 2025-08-11 | Runtime 8 ms | Memory 42.5 MB

class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> hm = new HashMap<>();
        for(char c : s.toCharArray()){
            if(hm.containsKey(c)){
                hm.put(c,hm.get(c)+1);
            }
            else{
                hm.put(c,1);
            }
        }
        int count = 0;
        boolean odd = false;
        for(Map.Entry e : hm.entrySet()){
            if(((int)e.getValue()%2)==0){
                count += (int)e.getValue();
            }
            else{
                odd = true;
                count += ((int)e.getValue()/2)*2;
            }
        }

        return odd ? count+1 : count;
    }
}