// Binary Tree to BST (Easy)
// https://www.geeksforgeeks.org/problems/binary-tree-to-bst/1
// Correct 2026-09-15 13:46:50 | C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void inorder(Node *root, vector<int> &v){
        if(!root){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
  
    void fill(Node *root, vector<int> &v, int &i){
        if(!root){
            return;
        }
        fill(root->left, v, i);
        root->data = v[i++];
        fill(root->right, v, i);
    }
  
    Node *binaryTreeToBST(Node *root) {
        // code here
        vector<int> v;
        inorder(root,v);
        sort(v.begin(), v.end());
        int i = 0;
        fill(root,v,i);
        return root;
    }
};