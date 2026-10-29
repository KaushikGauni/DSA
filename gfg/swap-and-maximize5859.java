// Maximize Adjacent Diff Sum in Circular (Easy)
// https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1
// Correct 2022-09-21 20:50:41 | Java

//User function Template for Java




class GFG
{
    long maxSum(long arr[] ,int n)
    {
        Arrays.sort(arr);
        int i =0;
        int j= n-1;
        long sum =0;
        while(i<j){
            sum = sum + Math.abs(arr[i]-arr[j]);
            sum = sum + Math.abs(arr[i+1]-arr[j]);
            i++;
            j--;
        }
        sum = sum + Math.abs(arr[0]-arr[i]);
        return sum;
    }
}

