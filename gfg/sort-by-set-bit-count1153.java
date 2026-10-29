// Sort by Set Bit Count (Easy)
// https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
// Correct 2022-10-12 21:23:35 | Java



//User function Template for Java


class Compute  
{ 
    static void sortBySetBitCount(Integer arr[], int n)
    { 
        // Your code goes here
        Arrays.sort(arr,(a,b)->Integer.compare(Integer.bitCount(b),Integer.bitCount(a)));
    } 
}
