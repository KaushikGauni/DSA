// Missing in Array (Easy)
// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
// Correct 2022-09-20 20:23:01 | Java



// User function Template for Java

class Solution {
    int MissingNumber(int array[], int n) {
        // Your Code Here
        int n1 = (n*(n+1))/2;
        int n2 = 0;
        for(int i=0;i<array.length;i++){
            n2 = n2 + array[i];
        }
        return n1-n2;
    }
}