// Median of Array (Basic)
// https://www.geeksforgeeks.org/problems/find-the-median0527/1
// Correct 2022-10-15 17:38:54 | Java



//User function Template for Java

class Solution
{
    public int find_median(int[] v)
    {
        // Code here
        Arrays.sort(v);
        if(v.length%2!=0){
            return v[(v.length/2)];
        }
        
        return (int)(v[v.length/2]+v[(v.length/2) - 1])/2;
    }
}