// Minimum Sum of Absolute Differences of Pairs (Easy)
// https://www.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/1
// Correct 2026-10-07 11:01:00 | C++

class Solution {
  public:
    int findMinSum(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int res = 0;
        
        for(int i=0;i<a.size();i++){
            res += abs(a[i]-b[i]);
        }
        
        return res;
    }
};