// Kth Smallest (Medium)
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Correct 2023-04-15 18:08:42 | Java



//User function Template for Java

class Solution{
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    { 
        //Your code here
        Arrays.sort(arr);
        return arr[k-1];
    } 
}
