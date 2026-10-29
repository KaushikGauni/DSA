// Array Leaders (Easy)
// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Correct 2023-06-26 21:31:46 | Java



class Solution{
    //Function to find the leaders in the array.
    static ArrayList<Integer> leaders(int arr[], int n){
        // Your code here
         ArrayList<Integer> result = new ArrayList<>();
       int max = arr[n-1];
       
       for(int i=n-1; i>=0; i--) {
           
           if (arr[i]>=max) {
               
           result.add(arr[i]);
              max = arr[i];
           }
       
       }
       
       Collections.reverse(result);
       
       return result;
    }
}
