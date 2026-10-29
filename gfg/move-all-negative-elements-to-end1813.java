// Move all Negatives to End (Easy)
// https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
// Correct 2022-09-21 20:58:55 | Java



//User function Template for Java

class Compute {
    
    public void Rearrange(long a[], long n)
    {
        // Your code goes here
        long res[] = new long[(int)n];
        long k = 0;
        for(long i =0;i<n;i++){
            if(a[(int)i]<0){
                res[(int)k++] = a[(int)i];
            }
        }
        
        for(long i=0;i<n;i++){
            if(a[(int)i]>=0){
                res[(int)k++] = a[(int)i];
            }
        }
        
        for(long i=0;i<n;i++){
            a[(int)i] = res[(int)i];
        }
    }
}