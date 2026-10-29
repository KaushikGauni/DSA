// Minimum in BST (Easy)
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
// Correct 2026-09-02 21:24:44 | C++

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        while(root->left){
            root = root->left;
        }
        
        return root->data;
    }
};