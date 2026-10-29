// Min and Max in Array (Basic)
// https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
// Correct 2026-09-04 13:41:59 | C++

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int min_element = INT_MAX, max_element = INT_MIN;
        int n = arr.size(), i = 0;
        if(n%2!=0){
            min_element = max_element = arr[0];
            i = 1;
        }
        else{
            if(arr[0]<arr[1]){
                min_element = arr[0];
                max_element = arr[1];
            }
            else{
                min_element = arr[1];
                max_element = arr[0];
            }
            i = 2;
        }
        
        while(i<n-1){
            if(arr[i] < arr[i+1]){
                min_element = min(min_element, arr[i]);
                max_element = max(max_element, arr[i+1]);
            }
            else{
                min_element = min(min_element, arr[i+1]);
                max_element = max(max_element, arr[i]);
            }
            i += 2;
        }
        
        return {min_element, max_element};
    }
};