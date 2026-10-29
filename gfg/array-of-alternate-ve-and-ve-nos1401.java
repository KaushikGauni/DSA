// Alternate Positive Negative (Easy)
// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
// Correct 2022-09-25 19:15:58 | Java



//User function Template for Java




class Solution {
    void rearrange(int arr[], int n) {
        // code here
        Queue<Integer> pos = new LinkedList<>();
            Queue<Integer> neg = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                if(arr[i]>=0){
                    pos.add(arr[i]);
                }
                else{
                    neg.add(arr[i]);
                }
            }

            for(int i=0;i<n;){
                if(!pos.isEmpty()){
                    arr[i] = pos.peek();
                    pos.remove();
                    i++;
                }

                if(!neg.isEmpty()){
                    arr[i] = neg.peek();
                    neg.remove();
                    i++;
                }
            }
    }
}