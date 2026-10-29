// Maximum Difference Between Increasing Elements
// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
// Accepted 2023-07-17 | Runtime 0 ms | Memory 41 MB

class Solution {
    public int maximumDifference(int[] nums) {
        int max = -1;
        int least = Integer.MAX_VALUE;
        int curr = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<least){
                least = nums[i];
            }
            curr = nums[i] - least;
            if(max < curr){
                max = curr;
            }
        }   

        return max==0 ? -1 : max;
    }
}