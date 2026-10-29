// Sort Colors
// https://leetcode.com/problems/sort-colors/
// Accepted 2025-07-26 | Runtime 0 ms | Memory 42.4 MB

class Solution {
    public void sortColors(int[] nums) {
        int a = 0,b=0,c=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                a++;
            }
            else if(nums[i]==1){
                b++;
            }
            else{
                c++;
            }
        }
        for(int j=0;j<a;j++){
            nums[j] = 0;
        }
        for(int j=a;j<a+b;j++){
            nums[j] = 1;
        }
        for(int j=a+b;j<a+b+c;j++){
            nums[j] = 2;
        }
    }
}