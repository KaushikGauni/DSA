// Squares in Triangle (Easy)
// https://www.geeksforgeeks.org/problems/maximum-number-of-22-squares/1
// Correct 2022-09-20 19:51:03 | Java



//User function Template for Java

class Solution
{
    public static long numberOfSquares(long base)
    {
        //code here
        long area = (base-2)/2;
        long ans = area*(area+1)/2;
        
        return ans;
    }
}