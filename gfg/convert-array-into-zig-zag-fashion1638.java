// Convert To Zig-Zag (Easy)
// https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
// Correct 2022-10-15 17:16:43 | Java



// User function Template for Java

class Solution {
    void zigZag(int arr[], int n) {
        // code here
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                if(arr[i]>arr[i+1]){
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
                else{
                    continue;
                }
            }
            else{
                if(arr[i]<arr[i+1]){
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
    }
}