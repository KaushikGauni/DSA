// Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Accepted 2026-10-12 | Runtime 0 ms | Memory 17.5 MB

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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* curr = root;
        while(curr->right){
            curr = curr->right;
        }
        curr->right = temp;
    }
};