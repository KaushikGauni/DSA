// Count Frequent Elements (Easy)
// https://www.geeksforgeeks.org/problems/count-element-occurences/1
// Correct 2022-10-12 21:12:31 | Java



class Solution 
{
    //Function to find all elements in array that appear more than n/k times.
    public int countOccurence(int[] arr, int n, int k) 
    {
        // your code here,return the answer
        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            max = Math.max(max,arr[i]);
        }
        
        int[] count = new int[max+1];
        
        int mincount = n/k;
        
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        int res = 0;
        for(int i=0;i<count.length;i++){
            if(count[i]>mincount){
                res++;
            }
        }
        
        return res;
    }
}
