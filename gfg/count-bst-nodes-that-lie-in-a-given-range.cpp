// Count BST Nodes in Range (Medium)
// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
// Correct 2026-09-15 14:47:43 | C++

/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int l, int h) {
        // code here   
        if(!root){
            return 0;
        }
        if(root->data < l){
            return getCount(root->right, l, h);
        }
        if(root->data > h){
            return getCount(root->left, l, h);
        }
        return 1 + getCount(root->left,l ,h) + getCount(root->right, l, h);
    }
};