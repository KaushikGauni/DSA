// Count Subarrays with XOR (Medium)
// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
// Correct 2026-09-16 10:47:08 | C++

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> hm;
        hm[0] = 1;
        long long count = 0;
        int x = 0;
        
        for(int i : arr){
            x ^= i;
            
            if(hm.count(k^x)){
                count += hm[k^x];
            }
            
            hm[x]++;
        }
        
        return count;
    }
};