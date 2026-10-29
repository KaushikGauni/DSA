// Assign Cookies
// https://leetcode.com/problems/assign-cookies/
// Accepted 2026-06-25 | Runtime 10 ms | Memory 44.7 MB

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int greed = 0, size = 0, count = 0;
        while(greed<g.size() && size<s.size()){
            if(g[greed]<=s[size]){
                count++;
                greed++;
            }
            size++;
        }

        return count;
    }

};