// Binary Search
// https://leetcode.com/problems/binary-search/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 31.2 MB

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                high = mid - 1;
            }
            else if(arr[mid]<target){
                low = mid + 1;
            }
        }

        return -1;
    }
};