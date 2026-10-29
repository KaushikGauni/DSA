// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Accepted 2025-08-07 | Runtime 3 ms | Memory 58.3 MB

class Solution {
    public int maxArea(int[] height) {
        int max_area = Integer.MIN_VALUE, area = 0;
        int i = 0, j = height.length-1;
        while(i<j){
            int a = height[i];
            int b = height[j];
            if(a<=b){
                area = a*(j-i);
                i++;
            }
            else{
                area = b*(j-i);
                j--;
            }
            max_area = Math.max(area,max_area);
        }

        return max_area;
    }
}