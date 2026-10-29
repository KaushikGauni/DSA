// Maximum Length Chain of Pairs (Medium)
// https://www.geeksforgeeks.org/problems/maximum-length-chain-of-pairs/1
// Correct 2026-10-07 11:30:07 | C++

class Solution {
  public:
    int maxChainLen(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end(), [](auto a, auto b){
           return a[1] < b[1]; 
        });
        
        int last = arr[0][1];
        int res = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] > last){
                res++;
                last = arr[i][1];
            }
        }
        
        return res;
    }
};
