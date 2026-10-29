// Max Chunks To Make Sorted
// https://leetcode.com/problems/max-chunks-to-make-sorted/
// Accepted 2026-08-14 | Runtime 0 ms | Memory 9.1 MB

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0,res=0;
        for(int i=0;i<arr.size();i++){
            maxVal = max(maxVal, arr[i]);
            if(maxVal == i){
                res++;
            }
        }

        return res;
    }
};