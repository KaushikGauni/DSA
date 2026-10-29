// Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/
// Accepted 2023-07-15 | Runtime 7 ms | Memory 41.6 MB

class Solution {
    public boolean isIsomorphic(String s, String t) {
        int a[] = new int[512];
        for(int i=0;i<s.length();i++){
            if(a[s.charAt(i)]!=a[t.charAt(i)+256]){
                return false;
            }
            a[s.charAt(i)] = a[t.charAt(i)+256] = i+1;
        }
        return true;
    }
}