// Largest Subarray with 0 Sum (Medium)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Correct 2023-05-30 19:21:30 | Java



class GfG
{
    int maxLen(int arr[], int n)
    {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int maxi = 0;
        int sum = 0;
        for(int i = 0 ; i<n;i++){
            sum+=arr[i];
            if(sum==0){ // 1 -1 2 3 >> sum for 0 and 1st pos = 0, so length is i+1 = 2
                maxi =i+1;
            }
            else{
                if(map.get(sum)!= null){ //check if sum exists or not
                    maxi = Math.max(maxi,i- map.get(sum));
                }
                else{
                    map.put(sum,i);
                }
            }
        }
        return maxi;
    }
}