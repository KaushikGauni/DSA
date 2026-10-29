// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Accepted 2026-06-27 | Runtime 0 ms | Memory 15 MB

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;

        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                int idx = ltr ? i : s-i-1;
                temp[idx] = node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            ltr = !ltr;
            res.push_back(temp);
        }

        return res;
    }
};