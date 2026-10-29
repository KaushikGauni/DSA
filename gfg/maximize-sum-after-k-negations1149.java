// Maximize Sum After k Negations (Easy)
// https://www.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1
// Correct 2022-10-12 21:03:23 | Java



//User function Template for Java


class Solution {

    public static long maximizeSum(long a[], int n, int k)
    {
        // Your code goes here   
        Arrays.sort(a);
        long sum = 0;
        for(int i=0;i<n;i++){
            if(a[i]<0 && k>0){
                a[i] = -a[i];
                k--;
            }
        }
        
        long min = Long.MAX_VALUE;
        for(int j=0;j<n;j++){
            sum+= a[j];
            min = Math.min(min,a[j]);
        }
        if(k%2!=0){
            sum = sum - 2 * min;
        }
        
        return sum;
    }
}