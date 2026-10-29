// Flood Fill
// https://leetcode.com/problems/flood-fill/
// Accepted 2025-08-11 | Runtime 0 ms | Memory 44.8 MB

class Solution {
    public void fill(int[][] res, int sr, int sc, int color, int oldColor){
        if((sr<0) || (sr>res.length-1) || (sc<0) || (sc>res[0].length-1)){
            return;
        }
        if(res[sr][sc]!=oldColor){
            return;
        }
        res[sr][sc] = color;
        fill(res,sr-1,sc,color,oldColor);
        fill(res,sr+1,sc,color,oldColor);
        fill(res,sr,sc-1,color,oldColor);
        fill(res,sr,sc+1,color,oldColor);
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int[][] res = image;
        int oldColor = image[sr][sc];
        if(oldColor==color){
            return res;
        }
        fill(res, sr, sc, color, oldColor);
        return res;
    }

}