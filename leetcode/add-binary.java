// Add Binary
// https://leetcode.com/problems/add-binary/
// Accepted 2025-09-06 | Runtime 1 ms | Memory 42.1 MB

class Solution {
    public static String addBinary(String a, String b) {
        StringBuilder s = new StringBuilder();
        int i=a.length()-1, j=b.length()-1;
        int carry = 0;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0){
                sum += a.charAt(i) - '0';
                i--;
            }
            if(j>=0){
                sum += b.charAt(j) - '0';
                j--;
            }
            s.append(sum%2);
            carry = sum / 2;
        }
        if(carry!=0){
            s.append(carry);
        }
        return s.reverse().toString();
    }
}