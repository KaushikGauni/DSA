// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
// Accepted 2026-06-27 | Runtime 0 ms | Memory 18.4 MB

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
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode){
            return true;
        }

        if(!leftNode || !rightNode){
            return false;
        }

        if(leftNode->val == rightNode->val){
            return compare(leftNode->left,rightNode->right) && compare(leftNode->right, rightNode->left);
        }

        return false;
    }
};