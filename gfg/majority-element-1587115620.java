// Majority Element (Medium)
// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
// Correct 2023-04-15 17:57:06 | Java



//User function Template for Java

class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code here
        int n = size;
        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            max = Math.max(max,a[i]);
        }
        int[] count = new int[max+1];
        for(int i=0;i<n;i++){
            count[a[i]]++;
        }
        for(int i=0;i<max+1;i++){
            if(count[i]>n/2){
                return i;
            }
        }
        return -1;
    }
}