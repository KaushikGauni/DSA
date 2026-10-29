// Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Accepted 2026-09-26 | Runtime 0 ms | Memory 27.9 MB

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
    int sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        calcSum(root);
        return sum;
    }

    int calcSum(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = max(0, calcSum(root->left));
        int right = max(0, calcSum(root->right));

        sum = max(sum, root->val + left + right);

        return root->val + max(left,right);
    }
};