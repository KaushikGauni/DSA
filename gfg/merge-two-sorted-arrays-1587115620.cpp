// Merge Without Extra Space (Medium)
// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// Correct 2026-09-22 16:15:35 | C++

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int i = a.size() - 1, j = 0;
        while(i>=0 && j<b.size()){
            if(a[i]>b[j]){
                swap(a[i],b[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};