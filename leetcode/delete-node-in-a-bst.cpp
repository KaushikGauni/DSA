// Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// Accepted 2026-09-15 | Runtime 0 ms | Memory 34.2 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(key == root->val){
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(root->left && !root->right){
                TreeNode *temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            else if(root->right && !root->left){
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else{
                TreeNode* pred = root->left;
                while(pred->right){
                    pred = pred->right;
                }
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};