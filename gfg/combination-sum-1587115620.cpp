// Target Sum Combinations (Medium)
// https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1
// Correct 2026-09-10 15:45:16 | C++

class Solution {
  public:
    vector<vector<int>> res;
    
    void backtrack(int i, vector<int> &arr, vector<int> &temp, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        
        if(target < 0 || i >= arr.size()){
            return;
        } 
        
        if(arr[i]<=target){
            temp.push_back(arr[i]);
            backtrack(i,arr,temp,target-arr[i]);
            temp.pop_back();
        }
        
        backtrack(i+1,arr,temp,target);
    }
    
    
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<int> temp;
        backtrack(0,arr,temp,target);
        return res;
    }
};