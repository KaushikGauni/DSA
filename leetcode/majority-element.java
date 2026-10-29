// Majority Element
// https://leetcode.com/problems/majority-element/
// Accepted 2025-08-14 | Runtime 2 ms | Memory 53 MB

class Solution {
    public int majorityElement(int[] nums) {
        int candidate = -1 , count = 0;
        for(int i : nums){
            if(count==0){
                candidate = i;
                count++;
            }
            else if(candidate==i){
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
}