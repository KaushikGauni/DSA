// Convert 1D Array Into 2D Array
// https://leetcode.com/problems/convert-1d-array-into-2d-array/
// Accepted 2023-07-17 | Runtime 4 ms | Memory 55 MB

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if(original.length!=m*n) return new int[0][];
        int[][] res = new int[m][n];
        int row=0,col=0;
        for(int i : original){
            res[row][col++]=i;
            if(col==n){
                col = 0;
                row++;
            }
        }
        return res;
    }
}