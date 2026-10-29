// Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// Accepted 2025-08-14 | Runtime 13 ms | Memory 59 MB

class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for(int i : nums){
            if(hs.contains(i)){
                return true;
            }
            else{
                hs.add(i);
            }
        }

        return false;
    }
}