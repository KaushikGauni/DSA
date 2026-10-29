// Search in BST (Easy)
// https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1
// Correct 2026-09-02 21:23:42 | C++

/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root){
            return false;
        }
        
        if(root->data == key){
            return true;
        }
        
        if(key < root->data){
            return search(root->left, key);
        }
        
        return search(root->right, key);
    }
};