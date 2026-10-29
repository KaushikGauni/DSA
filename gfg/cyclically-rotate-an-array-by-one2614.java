// Rotate Array by One (Basic)
// https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// Correct 2022-09-21 20:05:11 | Java



//User function Template for Java

class Compute {
    
    public void rotate(int arr[], int n)
    {
        int a = arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i] = arr[i-1];
        }
        
        arr[0] = a;
    }
}