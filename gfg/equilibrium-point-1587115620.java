// Equilibrium Point (Easy)
// https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
// Correct 2023-04-15 18:28:30 | Java



class Solution {

    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {

        // Your code here
        if(n==1){
            return 1;
        }
        int leftsum = 0;
        int rightsum = 0;
        for(int i=0;i<n;i++){
            rightsum += arr[i];
        }
        for(int i=1;i<n;i++){
            leftsum += arr[i-1];
            rightsum -= arr[i-1]+arr[i];
            if(leftsum==rightsum){
                return i+1;
            }
            else{
                rightsum += arr[i];
            }
        }
        return -1;
    }
}
