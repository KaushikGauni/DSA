// Indexes of Subarray Sum (Medium)
// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
// Correct 2022-10-15 17:10:52 | Java



class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
        // Your code here
        ArrayList<Integer> al = new ArrayList<>();
        int left = 0,right =0,sum = 0;
        if(s==0){
            al.add(-1);
            return al;
        }
        try{
            while(left<=right){
                if(sum==s){
                    al.add(left+1);
                    al.add(right);
                    break;
                }
                if(sum<s){
                    sum+=arr[right];
                    right++;
                }
                if(sum>s){
                    sum-=arr[left];
                    left++;
                }
            }
        }
        
        catch(ArrayIndexOutOfBoundsException e){
                if(al.size()==0){
                al.add(-1);
            }
        }
        
        return al;
    }
}