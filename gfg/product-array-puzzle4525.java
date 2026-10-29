// Product Array Puzzle (Easy)
// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Correct 2022-09-24 19:34:19 | Java



//User function Template for Java


class Solution 
{ 
	public static long[] productExceptSelf(int nums[], int n) 
	{ 
        // code here
        long product = 1;
        int count = 0;
        long[] p = new long[nums.length];
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                continue;
            }
            product = product*nums[i];
        }
        
        for(int i=0;i<n;i++){
            if(count==0){
                p[i] = product/nums[i];
            }
            if(count == 1 && nums[i]==0){
                p[i] = product;
            }
            if(count==1 && nums[i]!=0){
                p[i] = 0;
            }
            if(count>1){
                p[i] = 0;
            }
        }
        
        return p;
	} 
} 
