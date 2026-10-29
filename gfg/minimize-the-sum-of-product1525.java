// Minimize Sum of Product (Easy)
// https://www.geeksforgeeks.org/problems/minimize-the-sum-of-product1525/1
// Correct 2023-05-30 22:26:57 | Java



//User function Template for Java


class Solution {

    public long minValue(long a[], long b[], long n) 
    {
        // Your code goes here
        Arrays.sort(a);
        Arrays.sort(b);
        long sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i]*b[(int)n-i-1];
        }
        
        return sum;
    }
}
// 1 1 3
// 4 5 6