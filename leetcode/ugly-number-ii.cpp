// Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/
// Accepted 2026-08-12 | Runtime 3 ms | Memory 11.2 MB

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n);
        arr[0] = 1;
        int i=0,j=0,k=0;
        for(int l=1;l<n;l++){
            arr[l] = min(arr[i]*2,min(arr[j]*3,arr[k]*5));
            if(arr[l]==arr[i]*2)i++;
            if(arr[l]==arr[j]*3)j++;
            if(arr[l]==arr[k]*5)k++;
        }

        return arr[n-1];
    }
};