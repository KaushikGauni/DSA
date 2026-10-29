// Balanced Tree Check (Easy)
// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Correct 2026-09-25 12:49:47 | C++

/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    bool isBalanced(Node* root) {
        // code here
        return height(root) != -1;
    }
    
    int height(Node* root){
        if(!root){
            return 0;
        }
        int leftHeight = height(root->left);
        
        if(leftHeight == -1){
            return -1;
        }
        
        int rightHeight = height(root->right);
        
        if(rightHeight == -1){
            return -1;
        }
        
        if(abs(leftHeight-rightHeight) > 1){
            return -1;
        }
        
        return 1 + max(leftHeight, rightHeight);
    }
};