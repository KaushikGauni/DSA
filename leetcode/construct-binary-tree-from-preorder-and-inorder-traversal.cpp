// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Accepted 2026-09-26 | Runtime 4 ms | Memory 27.3 MB

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
    unordered_map<int,int> hm;

    TreeNode* build(vector<int>& preorder, int &preIndex, int inStart, int inEnd){
        if(inStart > inEnd){
            return nullptr;
        }
        TreeNode* res = new TreeNode(preorder[preIndex++]);
        int pos = hm[res->val];
        res->left = build(preorder, preIndex, inStart, pos-1);
        res->right = build(preorder, preIndex, pos+1, inEnd);
        return res;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            hm[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, preIndex, 0, inorder.size()-1);
    }
};