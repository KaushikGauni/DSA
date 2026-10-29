// K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/
// Accepted 2025-11-25 | Runtime 37 ms | Memory 64.8 MB

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto &a , auto &b){
            return sqrt(pow(a[0],2)+pow(a[1],2)) < sqrt(pow(b[0],2)+pow(b[1],2));
        });
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            result.push_back(points[i]);
        }
        return result;
    }
};