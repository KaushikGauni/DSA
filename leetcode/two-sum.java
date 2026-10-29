// Two Sum
// https://leetcode.com/problems/two-sum/
// Accepted 2025-08-09 | Runtime 2 ms | Memory 45.3 MB

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int[] res = new int[2];
        for(int i=0;i<nums.length;i++){
            if(hm.containsKey(target-nums[i])){
                res[0] = i;
                res[1] = hm.get(target-nums[i]);
                return res;
            }
            hm.put(nums[i],i);
        }

        return res;
    }
}