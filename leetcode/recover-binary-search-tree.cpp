// Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/
// Accepted 2026-06-30 | Runtime 0 ms | Memory 61.3 MB

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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        int start = 0, end = 0, c = 0;
        inorder_traverse(root, inorder);
        for(int i=1;i<inorder.size();i++){
            if(inorder[i]->val < inorder[i-1]->val){
                if(c==0){
                    start = i-1;
                    end = i;
                    c++;
                }
                else{
                    end = i;
                }
            }
        }

        swap(inorder[start]->val, inorder[end]->val);
    }

    void inorder_traverse(TreeNode* root, vector<TreeNode*> &inorder){
        if(!root){
            return;
        }
        inorder_traverse(root->left, inorder);
        inorder.push_back(root);
        inorder_traverse(root->right, inorder);
    }
};