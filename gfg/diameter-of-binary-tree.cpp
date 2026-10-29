// Diameter of Binary Tree (Medium)
// https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Correct 2026-09-26 13:32:34 | C++

/* Structure of binary tree Node 
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

    int diameter(Node* root) {
        // code here
        int ans = 0;
        height(root,ans);
        return ans;
        
    }
    
    int height(Node* root, int &ans){
        if(!root){
            return 0;
        }
        
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        
        ans = max(ans, left+right);
        
        return 1 + max(left,right);
    }
};