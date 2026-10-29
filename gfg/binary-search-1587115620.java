// First Occurrence in Sorted (Easy)
// https://www.geeksforgeeks.org/problems/binary-search-1587115620/1
// Correct 2022-10-06 10:40:37 | Java



// User function Template for Java

class Solution {
    int binarysearch(int arr[], int n, int k) {
        // code here
        int start= 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(k<arr[mid]){
                end = mid - 1;
            }
            else if(k>arr[mid]){
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
        
        return -1;
    }
}