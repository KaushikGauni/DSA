// Search in a K-Step Array (Easy)
// https://www.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1
// Correct 2026-09-22 15:21:32 | C++

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int i = 0, n = arr.size();
        
        while(i<n){
            if(arr[i]==x){
                return i;
            }
            
            int jump = abs(x-arr[i]) / k;
            
            if(jump == 0){
                jump = 1;
            }
            
            i += jump;
        }
        
        return -1;
    }
};
