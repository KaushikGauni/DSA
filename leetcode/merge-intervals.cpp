// Merge Intervals
// https://leetcode.com/problems/merge-intervals/
// Accepted 2026-08-07 | Runtime 3 ms | Memory 23.9 MB

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end(), [](auto &a, auto &b){
            return a[0]<b[0];
        });
        vector<vector<int>> merged;
        merged.push_back(ints[0]);
        for(int i=1;i<ints.size();i++){
            auto &last = merged.back();
            if(last[1] >= ints[i][0]){
                last[1] = max(last[1],ints[i][1]);
            }
            else{
                merged.push_back(ints[i]);
            }
        }

        return merged;
    }
};