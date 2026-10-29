// LCA in  Binary Tree (Medium)
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// Correct 2026-09-26 14:02:19 | C++

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
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(!root || root->data == n1 || root->data == n2) return root;
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        if(left && right) return root;
        return left ? left : right;
    }
};