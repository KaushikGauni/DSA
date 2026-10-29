// Next Greater Element (Medium)
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Correct 2023-06-03 16:18:37 | Java



class Solution
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    { 
        // Your code here
        long[] res = new long[n];
        Stack<Long> stack = new Stack<>();
        for(int i=n-1;i>=0;i--){
            while(!stack.isEmpty()){
                if(arr[i]<stack.peek()){
                    break;
                }
                else{
                    stack.pop();
                }
            }
            if(stack.isEmpty()){
                res[i]=-1;
            }
            else{
                res[i] = stack.peek();
            }
            stack.push(arr[i]);
        }
        return res;
    } 
}