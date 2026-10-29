// K-th Missing Element in Natural Numbers (Medium)
// https://www.geeksforgeeks.org/problems/k-th-missing-element-in-natural-numbers/1
// Correct 2026-09-16 15:09:49 | C++

class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        int n = arr.size() + k;
        unordered_set<int> hs(arr.begin(), arr.end());
        int count = 0;
        for(int i=1;i<=n;i++){
            if(hs.count(i)){
                continue;
            }
            count++;
            if(count == k){
                return i;
            }
        }
        
        return -1;
    }
};