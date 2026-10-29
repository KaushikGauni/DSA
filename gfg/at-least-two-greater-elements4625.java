// At least Two Greater (Basic)
// https://www.geeksforgeeks.org/problems/at-least-two-greater-elements4625/1
// Correct 2022-10-15 17:47:38 | Java



//User function Template for Java

class Solution {
    public long[] findElements( long a[], long n)
    {
        // Your code goes here
        Arrays.sort(a);
        long[] l = new long[(int)n-2];
        for(int i=0;i<n-2;i++){
            l[i] = a[i];
        }
        
        return l;
    }
}