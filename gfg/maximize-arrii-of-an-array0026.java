// Max Value Permutation (Easy)
// https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1
// Correct 2022-09-21 20:41:56 | Java



//User function Template for Java


class Solution{
    
    int Maximize(int arr[], int n)
    {
        // Complete the function
        java.util.Arrays.sort(arr);
        long a = 0;
        for(int i=0;i<n;i++){
            a = a + (long)arr[i]*i;
        }
        
        
        return (int)(a%1000000007);
    }   
}

