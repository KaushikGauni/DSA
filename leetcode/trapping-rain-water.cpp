// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// Accepted 2026-09-20 | Runtime 0 ms | Memory 26.1 MB

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int sum = 0;
        while(i <= j){
            if(height[i] <= height[j]){
                if(leftMax > height[i]){
                    sum += (leftMax - height[i]);
                }
                else{
                    leftMax = height[i];
                }
                i++;
            }
            else{    
                if(rightMax > height[j]){
                    sum += (rightMax - height[j]);
                }
                else{
                    rightMax = height[j];
                }
                j--;
            }    
        }
        return sum;
    }
};