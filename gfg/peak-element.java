// Peak in Array (Medium)
// https://www.geeksforgeeks.org/problems/peak-element/1
// Correct 2022-09-20 20:40:33 | Java



/*Complete the function below*/

class Solution
{
	// Function to find the peak element
	// arr[]: input array
	// n: size of array a[]
	public int peakElement(int[] arr,int n)
    {
       //add code here.
       int max = 1;
       int loc = 1;
       for(int i=0;i<arr.length;i++){
           if(arr[i]>max){
               max = arr[i];
               loc = i;
           }
       }
       
       return loc;
    }
}