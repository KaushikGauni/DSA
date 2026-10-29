// Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/
// Accepted 2023-06-21 | Runtime 1 ms | Memory 44.2 MB

class Solution {
    public List<String> fizzBuzz(int n) {
        String[] arr = new String[n];
        for(int i=0;i<n;i++){
            if((i+1)%3==0 && (i+1)%5==0){
                arr[i] = "FizzBuzz";
            }
            else if((i+1)%3==0){
                arr[i] = "Fizz";
            }
            else if((i+1)%5==0){
                arr[i] = "Buzz";
            }
            else{
                arr[i] = Integer.toString(i+1);
            }
        }
        return Arrays.asList(arr);
    }
}