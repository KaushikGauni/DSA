// Minimum Distance in Array (Easy)
// https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1
// Correct 2022-11-20 11:34:50 | Java



// User function Template for Java

class Solution {
    int minDist(int arr[], int n, int x, int y) {
        // code here
        int res = Integer.MAX_VALUE,a=-1,b=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                a = i;
            }
            if(arr[i]==y){
                b= i;
            }
            if(a!=-1 && b!=-1){
                res = Math.min(res,Math.abs(a-b));
            }
        }
        
        if(res==Integer.MAX_VALUE||res==0){
            return -1;
        }
        
        return res;
    }
}