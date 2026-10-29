// Smallest Missing Multiple of K
// https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Accepted 2026-08-25 | Runtime 0 ms | Memory 24.3 MB

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // unordered_set<int> hs(nums.begin(), nums.end());
        unordered_map<int,bool> hm;
        for(int i : nums){
            if(i%k==0){
                hm[i/k] = true;
            }
        }

        int i = 1;
        while(true){
            if(!hm[i]){
                return i * k;
            }
            i++;
        }

        // int multiple = k;
        // while(hs.count(multiple)){
        //     multiple = multiple + k;
        // }
        // return multiple;
    }
};