// Smallest Subset with Greater Sum (Easy)
// https://www.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1
// Correct 2022-10-13 18:04:29 | Java



//User function Template for Java

class Solution { 
    int minSubset(int[] Arr,int N) { 
        
        Arrays.sort(Arr);
        long totalSum = 0;
        for(int i=0;i<N;i++){
            totalSum+= Arr[i];
        }
        int k = 1;
        long sum = 0;
        for(int i=N-1;i>=0;i--){
            sum+= Arr[i];
            if(sum>totalSum-sum){
                return k;
            }
            else{
                k++;
            }
        }
        
        return k;
    }
}