// Convert to Mirror Tree (Easy)
// https://www.geeksforgeeks.org/problems/mirror-tree/1
// Correct 2025-10-14 11:25:40 | C++

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root==NULL){
            return;
        }
        Node* newNode = root->left;
        root->left = root->right;
        root->right = newNode;
        mirror(root->left);
        mirror(root->right);
    }
};