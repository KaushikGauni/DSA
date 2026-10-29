// Value Equal to Position (Basic)
// https://www.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
// Correct 2022-09-21 19:32:34 | Java



//User function Template for Java


class Solution {
    ArrayList<Integer> valueEqualToIndex(int arr[], int n) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            if(arr[i]==i+1){
                list.add(i+1);
            }
        }
        
        return list;
    }
}