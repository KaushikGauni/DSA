// Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// Accepted 2026-06-28 | Runtime 0 ms | Memory 18.9 MB

class Solution {
public:
    int histogramArea(vector<int> &heights){
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
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

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea,histogramArea(heights));
        }

        return maxArea;
    }
};