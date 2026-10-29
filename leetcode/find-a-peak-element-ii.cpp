// Find a Peak Element II
// https://leetcode.com/problems/find-a-peak-element-ii/
// Accepted 2026-06-23 | Runtime 0 ms | Memory 50.1 MB

class Solution {
public:

    int find_large(vector<vector<int>>& mat, int mid, int n, int m){
        int max = 0;
        for(int i=0;i<n;i++){
            if(mat[max][mid] < mat[i][mid]){
                max = i;
            }

        }
        return max;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            int large = find_large(mat, mid, n, m);
            int left = (mid>0) ? mat[large][mid-1] : -1;
            int right = (mid<m-1) ? mat[large][mid+1] : -1;
            if(mat[large][mid]>left && mat[large][mid]>right){
                return {large,mid};
            }
            else if(mat[large][mid]<left){
                high = mid - 1;
            }
            else if(mat[large][mid]<right){
                low = mid + 1;
            }
        }

        return {-1,-1};
    }


};