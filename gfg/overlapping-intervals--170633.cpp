// Overlapping Intervals (Medium)
// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1
// Correct 2026-09-22 09:43:11 | C++

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        res.push_back(arr[0]);
        
        for(int i = 1;i<arr.size();i++){
            auto &last = res.back();
            if(last[1] >= arr[i][0]){
                last[1] = max(last[1],arr[i][1]);
            }
            else{
                res.push_back(arr[i]);
            }
        }
        
        return res;
    }
};