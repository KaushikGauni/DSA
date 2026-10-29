// Single Number II
// https://leetcode.com/problems/single-number-ii/
// Accepted 2023-07-04 | Runtime 620 ms | Memory 44.5 MB

class Solution {
    public int singleNumber(int[] nums) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int i : nums){
            list.add(i);
        }
        Collections.sort(list);
        for(int i : nums){
            if(list.lastIndexOf(i)-list.indexOf(i)==0){
                return i;
            }
        }
        return -1;
    }
}