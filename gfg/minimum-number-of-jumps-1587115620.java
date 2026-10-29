// Minimum Jumps (Medium)
// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Correct 2023-06-03 16:09:18 | Java



class Solution{
    static int minJumps(int[] arr){
        // your code here
        int count = 0;
        int len = arr.length;
        int max = 0;
        int reach = 0;
        for(int i=0;i<len-1;i++){
            if(i+arr[i]>max){
                max = i+arr[i];
            }
            if(i==reach){
                count++;
                reach = max;
            }
            
            if(arr[i]==0 && i==max){
                return -1;
            }
        }
        return count;
    }
}