// Final Value of Variable After Performing Operations
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Accepted 2022-08-17 | Runtime 2 ms | Memory 43.4 MB

class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x=0;
        for(int i=0;i<operations.length;i++){
            if(operations[i].equals("X++") || operations[i].equals("++X")){
                x = x + 1;
            }
            else if(operations[i].equals("X--") || operations[i].equals("--X")){
                x = x - 1;
            }
        }
        
        return x;
    }
}