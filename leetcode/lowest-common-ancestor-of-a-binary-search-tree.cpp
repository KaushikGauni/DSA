// Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Accepted 2026-08-16 | Runtime 25 ms | Memory 23.3 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){
            return root;
        }

        if(((p->val<root->val) && (root->val<q->val)) || ((q->val<root->val) && (root->val<p->val))){
            return root;
        }

        else if((p->val<root->val) && (q->val<root->val)){
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }
};