// Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Accepted 2025-12-26 | Runtime 98 ms | Memory 88.2 MB

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
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return counter(root, root->val);
    }
    int counter(TreeNode* root, int maxval){
        if(!root){
            return 0;
        }
        int count = (root->val>=maxval) ? 1 : 0;
        maxval = max(root->val, maxval);
        return count + counter(root->left, maxval)+
        counter(root->right, maxval);

    }
};