// Reverse Array (Easy)
// https://www.geeksforgeeks.org/problems/reverse-an-array/1
// Correct 2026-09-18 11:31:34 | C++

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int i = 0, j = arr.size() - 1 ;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
        
        return;
    }
};