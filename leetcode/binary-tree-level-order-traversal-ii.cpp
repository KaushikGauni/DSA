// Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Accepted 2026-07-01 | Runtime 3 ms | Memory 15.8 MB

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.push_back(temp);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};