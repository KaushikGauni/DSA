// Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/
// Accepted 2026-08-19 | Runtime 0 ms | Memory 13.2 MB

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int miss = arr[mid] - (mid + 1);
            if(miss < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low + k;

    }
};