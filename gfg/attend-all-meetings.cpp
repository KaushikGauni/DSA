// Meeting Rooms (Easy)
// https://www.geeksforgeeks.org/problems/attend-all-meetings/1
// Correct 2026-08-05 15:27:09 | C++

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<arr[i-1][1]){
                return false;
            }
        }
        return true;
    }
};