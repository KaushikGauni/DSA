// First Repeating Element (Easy)
// https://www.geeksforgeeks.org/problems/first-repeating-element4018/1
// Correct 2023-07-13 21:39:42 | Java



// User function Template for Java

class Solution {
    // Function to return the position of the first repeating element.
    public static int firstRepeated(int[] arr, int n) {
        // Your code here
        HashMap<Integer,Integer> hm = new HashMap<>();
		    for(int i=0;i<n;i++){
		        if(hm.containsKey(arr[i])){
		            hm.put(arr[i],hm.get(arr[i])+1);
		        }
		        else{
		            hm.put(arr[i],1);
		        }
		    }
		    int i;
		    for(i=0;i<n;i++){
		        int a = arr[i];
		        if(hm.get(a)>1){
		            return i+1;
		        }
		    }
		    return -1;
    }
}
