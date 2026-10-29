// Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
// Accepted 2026-06-26 | Runtime 0 ms | Memory 23.7 MB

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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        height(root);
        return diameter;
    }

    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left+right);
        return 1 + max(left, right);
    }
};