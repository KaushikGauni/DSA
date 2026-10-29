// K Sized Subarray Maximum (Medium)
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// Correct 2023-06-03 16:37:47 | Java



//User function template for JAVA

class Solution
{
    //Function to find maximum of each subarray of size k.
    static ArrayList <Integer> max_of_subarrays(int arr[], int n, int k)
    {
        // Your code here
        ArrayList<Integer> result = new ArrayList<>();
        for(int i=0;i<n-k+1;i++){
            int max = Integer.MIN_VALUE;
            for(int j=0;j<k;j++){
                max = Math.max(max,arr[i+j]);
            }
            result.add(max);
        }
        return result;
    }
}