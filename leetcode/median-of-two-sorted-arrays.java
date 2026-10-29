// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Accepted 2023-06-21 | Runtime 5 ms | Memory 44.7 MB

class Solution {

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] arr = new int[nums1.length+nums2.length];
        int n = nums1.length;
        int m = nums2.length;
        int i = 0;
        for(i=0;i<n;i++){
            arr[i] = nums1[i];
        }
        for(int j=0;j<m;j++){
            arr[i] = nums2[j];
            i++;
        }
        Arrays.sort(arr);
        if(arr.length%2!=0){
            return (double)arr[arr.length/2];
        }
        int a = arr[(arr.length/2) - 1];
        int b = arr[arr.length/2];
        return (double)(a+b)/2;
    }
}