// Duplicates in Limited Range Array (Easy)
// https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// Correct 2023-05-30 18:00:57 | Java



class Solution {
    public static ArrayList<Integer> duplicates(int arr[], int n) {
        // code here
        TreeSet<Integer> al = new TreeSet<>();
        Arrays.sort(arr);
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                al.add(arr[i]);
            }
        }
        ArrayList<Integer> result = new ArrayList<>(al);
        if(result.isEmpty()){
            result.add(-1);
            return result;
        }
        return result;
    }
}
