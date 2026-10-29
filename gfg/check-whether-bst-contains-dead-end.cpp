// BST with Dead End (Medium)
// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
// Correct 2026-09-15 13:41:37 | C++

/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    unordered_set<int> hs;
    bool isDeadEnd(Node *root) {
        // Code here
        hs.insert(0);
        return solve(root);
    }
    
    bool solve(Node *root){
        if(!root){
            return false;
        }
        hs.insert(root->data);
        if(!root->left && !root->right){
            return hs.count(root->data - 1) && hs.count(root->data + 1);
        }
        return solve(root->left) || solve(root->right);
    }
};