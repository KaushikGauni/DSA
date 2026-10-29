// Count Distinct Elements in Every Window (Medium)
// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
// Correct 2026-09-17 16:16:01 | C++

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> hm;
        vector<int> res;
        int left = 0, right = 0;
        for(right=0;right<arr.size();right++){
            hm[arr[right]]++;
            if(right-left+1 > k){
                hm[arr[left]]--;
                if(hm[arr[left]]==0){
                    hm.erase(arr[left]);
                }
                left++;
            }
            if(right-left+1==k){
                res.push_back(hm.size());
            }
        }
        
        return res;
    }
};