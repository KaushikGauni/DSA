// Reverse Odd Levels of Binary Tree
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
// Accepted 2026-08-10 | Runtime 4 ms | Memory 77.2 MB

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left,root->right,0);
        return root;
    }

    void reverse(TreeNode* left, TreeNode* right, int i){
        if(!left || !right){
            return;
        }

        if(i%2==0){
            swap(left->val,right->val);
        }

        reverse(left->left,right->right, i+1);
        reverse(left->right,right->left, i+1);
    }
};