// Single Number
// https://leetcode.com/problems/single-number/
// Accepted 2025-07-26 | Runtime 13 ms | Memory 45.3 MB

class Solution {
    public int singleNumber(int[] nums) {
         HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
         for(int i=0;i<nums.length;i++){
            if(hm.containsKey(nums[i])){
                hm.put(nums[i], hm.get(nums[i])+1);
            }
            else{
                hm.put(nums[i],1);
            }
         }
         for(Map.Entry e : hm.entrySet()){
            if((int)e.getValue()==1){
                return (int)e.getKey();
            }
         }

         return -1;
    }
}