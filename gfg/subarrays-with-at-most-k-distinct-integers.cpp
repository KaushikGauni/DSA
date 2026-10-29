// Subarrays With At Most K Distinct (Medium)
// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1
// Correct 2026-09-17 16:30:54 | C++

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> hm;
        int right = 0, left = 0, count = 0;
        for(int right=0;right<arr.size();right++){
            hm[arr[right]]++;
            
            while(hm.size() > k){
                hm[arr[left]]--;
                if(hm[arr[left]]==0){
                    hm.erase(arr[left]);
                }
                left++;
            }
            
            count += right-left+1;
        }
        
        return count;
    }
};