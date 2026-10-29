// Maximum Weight Node (Easy)
// https://www.geeksforgeeks.org/problems/maximum-weight-node--170645/1
// Correct 2023-05-30 17:55:07 | Java



//User function Template for Java

class Solution{
    public int maxWeightCell(int N, int Edge[]){
       int weights[] = new int[N];
       int max = Integer.MIN_VALUE;
       for(int i=0;i<Edge.length;i++){
           if(Edge[i]==-1){
               continue;
           }
           weights[Edge[i]]+=i;
       }
       
       for(int i=0;i<N;i++){
           if(weights[i]>max){
               max = weights[i];
           }
       }
       
       for(int i=N-1;i>=0;i--){
           if(weights[i]==max){
               return i;
           }
       }
       
       return 0;
       
    }
}