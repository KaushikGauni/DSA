// Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Accepted 2026-09-03 | Runtime 0 ms | Memory 9.4 MB

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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root || !root->left){
            return -1;
        }

        int left = root->left->val == root->val ? findSecondMinimumValue(root->left) : root->left->val;
        int right = root->right->val == root->val ? findSecondMinimumValue(root->right) : root->right->val;

        if(left==-1) return right;
        if(right==-1) return left;

        return min(left,right);
    }
};