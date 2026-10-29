// Permute Arrays for Sum Threshold (Easy)
// https://www.geeksforgeeks.org/problems/permutations-in-array1747/1
// Correct 2026-09-22 15:04:52 | C++

class Solution {
  public:
    bool isPossible(int k, vector<int> &a, vector<int> &b) {
        // code here
        if(a.size() != b.size()){
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());
        
        for(int i=0;i<a.size();i++){
            if(a[i]+b[i] < k){
                return false;
            }
        }
        
        return true;
    }
};