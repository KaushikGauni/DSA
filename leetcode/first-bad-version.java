// First Bad Version
// https://leetcode.com/problems/first-bad-version/
// Accepted 2025-08-11 | Runtime 25 ms | Memory 40.8 MB

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start = 1, end = n;
        while(start<end){
            int mid = start + (end-start)/2;
            if(isBadVersion(mid)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
}