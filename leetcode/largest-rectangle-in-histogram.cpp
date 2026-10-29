// Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Accepted 2026-08-10 | Runtime 8 ms | Memory 81.5 MB

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<=heights.size();i++){
            while(!st.empty() && (i==heights.size() || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                int area = (right-left-1) * h;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};