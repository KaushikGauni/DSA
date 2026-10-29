// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
// Accepted 2026-08-07 | Runtime 0 ms | Memory 13.2 MB

class Solution {
public:

    bool bin_search(vector<int> &arr, int target){
        int left = 0, right = arr.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]<target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size()-1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]<target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(right<0){
            return false;
        }
        return bin_search(matrix[right],target);
    }
};