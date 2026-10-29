// Stickler Thief (Easy)
// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// Correct 2022-09-24 20:10:57 | Java



class Solution
{
    //Function to find the maximum money the thief can get.
    public int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0){
            return 0;
        }
        
        int val1 = arr[0];
        if(n==1){
            return val1;
        }
        
        int val2 = Math.max(arr[0],arr[1]);
        if(n==2){
            return val2;
        }
        
        int sum=0;
        for(int i=2;i<n;i++){
            sum = Math.max(arr[i]+val1,val2);
            val1 = val2;
            val2 = sum;
        }
        
        return sum;
    }
}