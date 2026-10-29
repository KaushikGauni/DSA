// Flood Fill
// https://leetcode.com/problems/flood-fill/
// Accepted 2026-07-01 | Runtime 0 ms | Memory 18 MB

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int oldColor){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()){
            return;
        }
        if(image[sr][sc]==oldColor){
            image[sr][sc] = color;
            dfs(image,sr+1,sc,color,oldColor);
            dfs(image,sr-1,sc,color,oldColor);
            dfs(image,sr,sc+1,color,oldColor);
            dfs(image,sr,sc-1,color,oldColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color){
            return image;
        }
        dfs(image,sr,sc,color,oldColor);
        return image;
    }
};