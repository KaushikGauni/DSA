// Two Unique Among Pairs (Medium)
// https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1
// Correct 2026-09-03 16:20:32 | C++

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int x = 0;
        for(int i : arr){
            x ^= i;
        }
        x = x & -x;
        
        int a = 0, b = 0;
        
        for(int i : arr){
            if(x&i){
                a ^= i;
            }
            else{
                b ^=i;
            }
        }
        if(a<b)
        return {a,b};
        
        return {b,a};
    }
};