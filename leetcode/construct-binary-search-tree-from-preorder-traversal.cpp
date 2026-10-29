// Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Accepted 2026-06-30 | Runtime 0 ms | Memory 16.3 MB

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

    TreeNode* bst(vector<int>& preorder, int &index, int bound){
        if(index == preorder.size() || preorder[index]>bound){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = bst(preorder, index, root->val);
        root->right = bst(preorder, index, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, bound = INT_MAX;
        return bst(preorder, index, bound);
    }
};