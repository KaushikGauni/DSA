// Largest BST Subtree (Hard)
// https://www.geeksforgeeks.org/problems/largest-bst/1
// Correct 2026-09-16 14:30:40 | C++

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    struct Info{
        bool isBST;
        int size;
        long long mn;
        long long mx;
    };
    
    Info solve(Node* root){
        if(!root){
            return {true,0,LLONG_MAX, LLONG_MIN};
        }
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        if(left.isBST && right.isBST && left.mx < root->data && root->data < right.mn){
            int size = 1 + left.size + right.size;
            return {true,size,min((long long)root->data,left.mn),max((long long)root->data,right.mx)};
        }
        
        return {false, max(left.size,right.size), LLONG_MIN, LLONG_MAX};
        
    }
    
    int largestBst(Node *root) {
        // code here
        return solve(root).size;
    }
    
    
};