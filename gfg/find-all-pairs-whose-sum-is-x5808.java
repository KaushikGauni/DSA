// All Pairs with Sum from 2 Arrays (Easy)
// https://www.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1
// Correct 2023-05-30 19:31:38 | Java



//User function Template for Java

/*
class pair  {  
    long first, second;  
    public pair(long first, long second)  
    {  
        this.first = first;  
        this.second = second;  
    }  
}
*/

class Solution {
    public pair[] allPairs( long A[], long B[], long N, long M, long X) {
        // Your code goes here
        ArrayList<pair> ans = new ArrayList<>();
        HashSet<Long> set = new HashSet<>();
        for(Long i:B){
            set.add(i);
        }
        Arrays.sort(A);
        for(Long i:A){
            if(set.contains(X-i)){
                ans.add(new pair(i,X-i));
            }
        }
        pair[] list = new pair[ans.size()];
        return ans.toArray(list);
    }
}