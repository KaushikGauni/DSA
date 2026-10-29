// Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/
// Accepted 2023-07-15 | Runtime 0 ms | Memory 40 MB

class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder st = new StringBuilder();
        while(columnNumber>0){
            char a = (char)((columnNumber%26==0?26:columnNumber%26)+64);
            st.append(a);
            columnNumber = (columnNumber%26==0 ? columnNumber/26-1 : columnNumber/26);
        }
        return st.reverse().toString();
    }
}