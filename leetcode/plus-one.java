// Plus One
// https://leetcode.com/problems/plus-one/
// Accepted 2023-07-15 | Runtime 0 ms | Memory 40.9 MB

class Solution {
    public int[] plusOne(int[] digits) {
        for(int i =digits.length-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}