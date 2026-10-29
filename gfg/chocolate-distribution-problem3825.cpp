// Chocolate Distribution Problem (Easy)
// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Correct 2026-09-04 13:48:52 | C++

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int i = 0, j = m-1;
        sort(a.begin(), a.end());
        int res = INT_MAX;
        while(i<a.size() && j<a.size()){
            res = min(res, a[j]-a[i]);
            j++;
            i++;
        }
        
        return res;
    }
};