// Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Accepted 2026-06-28 | Runtime 1 ms | Memory 27.4 MB

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

    TreeNode* build(vector<int> &postorder, int& postIndex, int inStart, int inEnd){
        if(inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postIndex]);
        postIndex--;
        int pos = hm[root->val];
        root->right = build(postorder, postIndex, pos+1, inEnd);
        root->left = build(postorder, postIndex, inStart , pos-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            hm[inorder[i]] = i;
        }
        int postIndex = postorder.size()-1;
        return build(postorder, postIndex, 0, inorder.size()-1);
    }
};