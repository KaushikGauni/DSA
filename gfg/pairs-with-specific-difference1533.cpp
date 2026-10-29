// Max Sum Pairing with Diff Less than K (Easy)
// https://www.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1
// Correct 2026-09-23 11:30:50 | C++

class Solution {
  public:
  
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int i = n-1;
        int sum = 0;
        while(i>0){
            if(arr[i]-arr[i-1] < k){
                sum += arr[i] + arr[i-1];
                i -= 2;
            }
            else{
                i--;
            }
        }
        
        return sum;
    }
};