// Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/
// Accepted 2026-08-18 | Runtime 2 ms | Memory 18.2 MB

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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return res;
        }
        help(root, "");
        return res;
    }
    void help(TreeNode* root, string curr){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            curr += to_string(root->val);
            res.push_back(curr);
        }
        curr += to_string(root->val)+"->";

        help(root->left, curr);
        help(root->right, curr);
    }
};