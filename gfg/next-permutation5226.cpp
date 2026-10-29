// Next Permutation (Medium)
// https://www.geeksforgeeks.org/problems/next-permutation5226/1
// Correct 2026-10-12 19:01:53 | C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int k = n-2;
        while(k >=0 && arr[k] >= arr[k+1]){
            k--;
        }
        if(k==-1){
            sort(arr.begin(), arr.end());
            return;
        }
        int i = n-1;
        while(i>=0 && arr[i] <= arr[k]){
            i--;
        }
        
        swap(arr[i],arr[k]);
        sort(arr.begin()+k+1,arr.end());
    }
};