// Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/
// Accepted 2026-08-18 | Runtime 0 ms | Memory 23.9 MB

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
    int ans;

    int findSum(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = findSum(root->left);
        int right = findSum(root->right);

        ans += abs(left - right);

        return root->val + left + right;
    }
    int findTilt(TreeNode* root) {
        findSum(root);
        return ans;
    }
};