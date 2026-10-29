// Check for BST (Medium)
// https://www.geeksforgeeks.org/problems/check-for-bst/1
// Correct 2025-08-04 21:32:19 | Java

/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    // Function to check whether a Binary Tree is BST or not.
    boolean isBST(Node root) {
        // code here.
        return isBSt(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    boolean isBSt(Node root, int min, int max){
        if(root==null){
            return true;
        }
        if(root.data<=min || root.data>=max){
            return false;
        }
        return isBSt(root.left, min, root.data) && isBSt(root.right, root.data, max);
    }
}