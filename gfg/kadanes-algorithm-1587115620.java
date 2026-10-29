// Kadane's Algorithm (Medium)
// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Correct 2023-07-09 20:46:17 | Java



class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long max = Integer.MIN_VALUE;
        long max1 = 0;
        for(int i=0;i<n;i++){
            max1 += arr[i];
            if(max1>max){
                max = max1;
            }
            if(max1<0){
                max1 = 0;
            }
        }
        return max;
    }
    
}

