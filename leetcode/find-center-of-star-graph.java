// Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/
// Accepted 2023-06-03 | Runtime 2 ms | Memory 73.4 MB

class Solution {
    public int findCenter(int[][] edges) {
        int[] count = new int[edges.length+2];
        for(int[] person : edges){
            count[person[0]]++;
            count[person[1]]++;
        }
        for(int i=0;i<count.length;i++){
            if(count[i]==edges.length){
                return i;
            }
        }
        return -1;
    }
}