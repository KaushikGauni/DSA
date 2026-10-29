// Maximum Product Subarray (Medium)
// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Correct 2023-06-03 16:34:30 | Java



class Solution {
    // Function to find maximum product subarray
    long maxProduct(int[] arr, int n) {
        // code here
        long pf = 1, sf = 1, res = Long.MIN_VALUE;
        for(int i=0;i<n;i++){
            pf *= arr[i];
            sf *= arr[n-i-1];
            res = Math.max(res,Math.max(pf,sf));
            if(pf==0){
                pf = 1;
            }
            if(sf==0){
                sf = 1;
            }
        }
        
        return res;
    }
}