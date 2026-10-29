// Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// Accepted 2023-07-03 | Runtime 362 ms | Memory 44.5 MB

class Solution {
    public int pivotIndex(int[] arr) {
        for(int i=0;i<arr.length;i++){
            int right = 0, left = 0;
            for(int j=i;j<arr.length;j++){
                right+= arr[j];
            }
            for(int j=i;j>=0;j--){
                left += arr[j];
            }
            right -= arr[i];
            left -= arr[i];
            if(right==left){
                return i;
            }
        }
        return -1;
    }
}