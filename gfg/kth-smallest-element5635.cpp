// Kth Smallest (Medium)
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Correct 2026-09-22 09:39:40 | C++

class Solution {
  public:
  
    int partition(vector<int> &arr, int i, int j){
        int pivot = arr[j];
        int low = i;
        
        for(int k=low;k<j;k++){
            if(arr[k] <= pivot){
                swap(arr[k],arr[low]);
                low++;
            }
        }
        
        swap(arr[low],arr[j]);
        return low;
    }
  
    int quickSelect(vector<int> &arr, int i, int j, int k){
        if(i==j){
            return arr[i];
        }
        
        int pivotIndex = partition(arr, i, j);
        
        if(pivotIndex == k){
            return arr[pivotIndex];
        }
        else if(pivotIndex < k){
            return quickSelect(arr,pivotIndex+1, j, k);
        }
        return quickSelect(arr,i,pivotIndex-1,k);
    }
  
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        return quickSelect(arr, 0, arr.size()-1, k-1);
    }
};