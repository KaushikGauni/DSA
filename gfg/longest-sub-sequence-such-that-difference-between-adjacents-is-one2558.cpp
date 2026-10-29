// Longest Subsequence with Adjacent Diff as 1 (Medium)
// https://www.geeksforgeeks.org/problems/longest-sub-sequence-such-that-difference-between-adjacents-is-one2558/1
// Correct 2026-09-23 11:34:15 | C++

class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int,int> hm;
        int ans = 0;
        for(int i : arr){
            int len = max(hm[i-1], hm[i+1]) + 1;
            hm[i] = max(len,hm[i]);
            ans = max(ans, hm[i]);
        }
        
        return ans;
    }
};