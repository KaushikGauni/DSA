// Pythagorean Triplet (Medium)
// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
// Correct 2022-09-27 19:30:00 | Java



//User function Template for Java



class Solution {
    boolean checkTriplet(int[] arr, int n) {
        // code here
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int a = arr[i]*arr[i];
                    int b = arr[j]*arr[j];
                    int c = arr[k]*arr[k];
                    if(a==b+c||b==a+c||c==a+b){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
}