// Largest Subarray with 0 Sum (Medium)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Correct 2026-09-17 15:19:31 | C++

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int> hm;
        int sum = 0, res = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum==0){
                res = i + 1;
            }
            else if(hm.count(sum)){
                res = max(res, i - hm[sum]);
            }
            else{
                hm[sum] = i;
            }
        }
        
        return res;
    }
};