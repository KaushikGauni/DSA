// Pair With Difference (Easy)
// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1
// Correct 2026-09-22 15:32:16 | C++


class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        unordered_set<int> hs;
        
        for(int i : arr){
            if(hs.count(i-x) || hs.count(i+x)){
                return true;
            }
            hs.insert(i);
        }
        
        return false;
    }
};
