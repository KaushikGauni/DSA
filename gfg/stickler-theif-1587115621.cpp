// Stickler Thief (Easy)
// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// Correct 2026-09-22 16:10:50 | C++

class Solution {
  public:
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int max1 = 0, max2 = 0;
        for(int i =0;i<arr.size();i++){
            int temp = max1;
            max1 = max(max2+arr[i],max1);
            max2 = temp;
        }
        
        return max1;
    }
};