// Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/
// Accepted 2025-12-13 | Runtime 39 ms | Memory 94 MB

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), count = 0;
        sort(begin(intervals), end(intervals),[](auto &a, auto &b){
            return a[1] < b[1];
        });
        int prev = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev){
                count++;
            }
            else{
                prev = intervals[i][1];
            }
        }
        return count;
    }
};
