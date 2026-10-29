// Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Accepted 2023-06-21 | Runtime 9 ms | Memory 44.3 MB

class Solution {
    public String reverseVowels(String s) {
        ArrayList<Integer> indices = new ArrayList<>();
        ArrayList<Character> chars = new ArrayList<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='A' || s.charAt(i)=='E' || s.charAt(i)=='I' || s.charAt(i)=='O' || s.charAt(i)=='U' || s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u'){
                indices.add(i);
                chars.add(s.charAt(i));
            }
        }
        StringBuilder st = new StringBuilder(s);
        Collections.reverse(chars);
        for(int i=0;i<indices.size();i++){
            st.setCharAt(indices.get(i),chars.get(i));
        }
        return st.toString();
    }
}