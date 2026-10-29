// Check Triplet With 0 Sum (Medium)
// https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
// Correct 2023-07-09 20:27:06 | Java



/*Complete the function below*/


class Solution
{
    // arr[]: input array
    // n: size of the array
    //Function to find triplets with zero sum.
	public boolean findTriplets(int arr[] , int n)
    {
        //add code here.
        boolean found = false;
        Arrays.sort(arr);
        for(int i=0;i<n-1;i++){
            int l = i+1;
            int r = n-1;
            int x = arr[i];
            while(l<r){
                if(x+arr[l]+arr[r]==0){
                    l++;
                    r--;
                    found = true;
                    break;
                }
                else if(x+arr[l]+arr[r]<0){
                    l++;
                }
                else{
                    r--;
                }
            }
            if(found){
                break;
            }
        }
        return found;
    }
}