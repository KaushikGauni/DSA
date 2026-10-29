// Bubble Sort (Easy)
// https://www.geeksforgeeks.org/problems/bubble-sort/1
// Correct 2023-07-26 17:00:47 | Java

//User function Template for Java

class Solution
{
    //Function to sort the array using bubble sort algorithm.
	public static void bubbleSort(int arr[], int n)
    {
        //code here
        for(int i =0 ;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
