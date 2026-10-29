// Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Accepted 2026-06-23 | Runtime 50 ms | Memory 18.8 MB

class Solution {
public:

    // bool bin_srch(vector<int> &arr, int target, int m){
    //     int low = 0, high = m-1;
    //     while(low<=high){
    //         int mid = low + (high - low) / 2;
    //         if(arr[mid]==target){
    //             return true;
    //         }
    //         else if(target>arr[mid]){
    //             low = mid + 1;
    //         }
    //         else{
    //             high = mid - 1;
    //         }
    //     }

    //     return false;
    // } ---> classic bin search ---written from scratch by kaushik at 2am 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }

        return false;
    }
};