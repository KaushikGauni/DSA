// Maximize Adjacent Diff Sum in Circular (Easy)
// https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1
// Correct 2026-10-07 12:13:19 | C++

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int sum = 0, i = 0, j = n-1;
    
        while(i<j){
            sum += abs(arr[i]-arr[j]);
            sum += abs(arr[i+1] - arr[j]);
            i++;
            j--;
        }
        
        return sum + abs(arr[0]-arr[i]);
    }
};
