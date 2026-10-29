// Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
// Accepted 2025-07-26 | Runtime 2 ms | Memory 50.5 MB

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0,count1=0;;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                count1++;
            }
            else{
                if(count1>count){
                    count = count1;
                }
                count1 = 0;
            }
        }

        return count1>count ? count1 : count;
    }
}