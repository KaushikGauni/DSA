// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Accepted 2026-09-15 | Runtime 0 ms | Memory 24.3 MB

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
    int res;
    void solve(TreeNode* root, int &k, int &count){
        if(!root){
            return;
        }
        solve(root->left, k, count);
        if(count >= k){
            return;
        }
        count++;
        if(count == k){
            res =  root->val;
        }
        solve(root->right,k,count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        res = 0;
        solve(root,k,count);
        return res;
    }
};