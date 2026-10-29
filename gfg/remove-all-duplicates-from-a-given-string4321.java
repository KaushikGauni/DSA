// String Duplicates Removal (Easy)
// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
// Correct 2022-09-27 19:48:22 | Java



//User function Template for Java


class Solution {
    String removeDuplicates(String str) {
        // code here
        HashSet<Character> hm = new HashSet<>();
        String s = "";
        for(int i=0;i<str.length();i++){
            int temp=0;
            if(!hm.contains(str.charAt(i))){
                hm.add(str.charAt(i));
                s = s + str.charAt(i);
            }
        }
        
        return s;
    }
}

