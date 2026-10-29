// Flatten BST to Sorted List (Medium)
// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
// Correct 2026-09-15 14:21:13 | C++

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    void inorder(Node* root, vector<int> &v){
        if(!root){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    void fill(Node* &res, vector<int> &v, int &i){
        if(i>=v.size()){
            return;
        }
        if(!res){
            res = new Node(v[i++]);
        }
        fill(res->right, v, i);
    }
    
    Node *flattenBST(Node *root) {
        // code here
        vector<int> v;
        inorder(root,v);
        Node* res = nullptr;
        int i = 0;
        fill(res, v, i);
        return res;
    }
};