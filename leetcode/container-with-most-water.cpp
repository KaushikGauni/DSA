// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Accepted 2026-09-22 | Runtime 0 ms | Memory 63 MB

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxArea = INT_MIN;
        while(i<j){
            int area = min(height[i],height[j]) * (j-i);
            maxArea = max(area,maxArea);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxArea;
    }
};