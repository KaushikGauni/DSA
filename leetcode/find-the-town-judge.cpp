// Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/
// Accepted 2025-10-13 | Runtime 24 ms | Memory 73.1 MB

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1,0);
        
        for(auto i : trust){
            count[i[0]]--;;
            count[i[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }

        return -1;

    }
};