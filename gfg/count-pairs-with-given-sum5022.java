// Pairs with 0 Sum (Medium)
// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// Correct 2022-09-24 14:11:47 | Java



//User function Template for Java

class Solution {
    int getPairsCount(int[] arr, int n, int k) {
        // code here
        int count = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            if (!hm.containsKey(arr[i]))
                hm.put(arr[i], 0);
            hm.put(arr[i], hm.get(arr[i]) + 1);
        }
        
        for(int i=0;i<n;i++){
            if(hm.get(k-arr[i])!=null){
                count = count + hm.get(k-arr[i]);
            }
            if(k-arr[i]==arr[i]){
                count--;
            }
        }
        
        return count/2;
        
    }
}
