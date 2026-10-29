// Delete Mid of Stack (Easy)
// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// Correct 2023-07-15 11:03:49 | Java



//User function Template for Java

class Solution
{
    //Function to delete middle element of a stack.
    public void deleteMid(Stack<Integer>s,int sizeOfStack){
        // code here
        Stack<Integer> tempstack = new Stack<>();
        while(s.size()>=tempstack.size()){
            tempstack.push(s.pop());
        }
        tempstack.pop();
        while(!tempstack.isEmpty()){
            s.push(tempstack.pop());
        }
    } 
}

