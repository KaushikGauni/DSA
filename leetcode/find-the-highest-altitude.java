// Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/
// Accepted 2023-06-27 | Runtime 1 ms | Memory 40.7 MB

class Solution {
    public int largestAltitude(int[] gain) {
        int[] heights = new int[gain.length+1];
        heights[0] = 0;
        for(int i=0;i<gain.length;i++){
            heights[i+1] = heights[i] + gain[i];
        }
        Arrays.sort(heights);
        return heights[heights.length-1];
    }
}