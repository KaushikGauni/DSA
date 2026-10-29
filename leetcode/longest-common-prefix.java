// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Accepted 2023-06-21 | Runtime 8 ms | Memory 41.3 MB

class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        if(strs.length==0){
            return "";
        }
        else if(strs.length==1){
            return strs[0];
        }
        String res = "";
        String a = strs[0];
        String b = strs[strs.length-1];
        int e = Math.min(a.length(),b.length());
        for(int i=0;i<e;i++){
            if(a.charAt(i)==b.charAt(i)){
                res = res + a.charAt(i);
            }
            else{
                break;
            }
        }

        return res;
    }
}