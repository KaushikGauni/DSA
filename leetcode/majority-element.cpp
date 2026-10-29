// Majority Element
// https://leetcode.com/problems/majority-element/
// Accepted 2026-07-28 | Runtime 0 ms | Memory 28 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = -1, count = 0;
        for(int i : nums){
            if(count == 0){
                cand = i;
                count++;
            }
            else if(cand == i){
                count++;
            }
            else{
                count--;
            }
        }

        return cand;
    }
};