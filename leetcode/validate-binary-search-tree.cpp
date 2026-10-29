// Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// Accepted 2026-09-15 | Runtime 1 ms | Memory 21.8 MB

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
    bool isValidBST(TreeNode* root) {
        return isValid(LLONG_MIN, root, LLONG_MAX);
    }

    bool isValid(long long left, TreeNode* root, long long right){
        if(!root){
            return true;
        }
        if(left < root->val && root->val < right){
            return isValid(left,root->left,root->val) && isValid(root->val, root->right, right);
        }

        return false;
    }
};