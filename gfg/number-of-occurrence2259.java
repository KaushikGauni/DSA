// Count Occurrences in Sorted (Medium)
// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Correct 2022-11-20 11:37:54 | Java



//User function Template for Java



class Solution {
    int count(int[] arr, int n, int x) {
        // code here
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                count++;
            }
        }
        
        return count;
    }
}