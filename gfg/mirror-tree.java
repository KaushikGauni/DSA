// Convert to Mirror Tree (Easy)
// https://www.geeksforgeeks.org/problems/mirror-tree/1
// Correct 2025-10-14 11:24:01 | Java

/*
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/

class Solution {
    void mirror(Node root) {
        // code here
        if(root==null){
            return;
        }
        Node newNode = root.left;
        root.left = root.right;
        root.right = newNode;
        mirror(root.left);
        mirror(root.right);
        
    }
}