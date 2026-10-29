// Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/
// Accepted 2023-07-15 | Runtime 1 ms | Memory 41.6 MB

class Solution {
    public int titleToNumber(String columnTitle) {
        if(columnTitle == null) return -1;
        int sum = 0;
        for(char c : columnTitle.toCharArray()){
            sum *= 26;
            sum += c - 'A' + 1;
        }
        return sum;
    }
}