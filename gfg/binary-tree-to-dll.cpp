// Binary Tree  to DLL (Hard)
// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1
// Correct 2026-09-02 21:22:03 | C++

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
  
    Node* prev, *head;
    Node* treeToDLL(Node* root) {
        // code here
        head = prev = nullptr;
        inorder(root);
        return head;
    }
    
    void inorder(Node* root){
        if(!root){
            return;
        }
        
        inorder(root->left);
        if(!prev){
            head = root;
        }
        else{
            prev->right = root;
            root->left = prev;
        }
        
        prev = root;
        
        inorder(root->right);
    }
};