// Max  Rectangle (Hard)
// https://www.geeksforgeeks.org/problems/max-rectangle/1
// Correct 2026-09-22 14:59:38 | C++

class Solution {
  public:
  
    int histogramArea(vector<int> &heights){
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int height = heights[st.top()];
                st.pop();
                
                
                int left = st.empty() ? -1 : st.top();
                int right = i;
                
                int w = right - left - 1;
                int area = w * height;
                maxArea = max(maxArea, area);
                
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            
            int left = st.empty() ? -1 : st.top();
            int right = heights.size();
            
            int w = right - left - 1;
            int area = w * height;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
  
    int maxArea(vector<vector<int>> &mat) {
        // code here
        vector<int> heights(mat[0].size());
        int maxArea = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, histogramArea(heights));
        }
        
        return maxArea;
    }
};