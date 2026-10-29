// Nth Root of M (Medium)
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// Correct 2023-07-26 17:04:25 | Java



//User function Template for Java

class Solution
{
    public int NthRoot(int n, int m)
    {
        // code here
        int start = 1 , end = m;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(Math.pow(mid,n)==m){
                return mid;
            }
            else if(Math.pow(mid,n)>m){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
}