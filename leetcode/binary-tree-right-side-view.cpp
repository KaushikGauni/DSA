// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
// Accepted 2026-06-27 | Runtime 0 ms | Memory 15.4 MB

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }

        queue<pair<TreeNode*,int>> q;
        map<int,int> hm;
        vector<int> res;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int height = q.front().second;
            q.pop();
            if(!hm.count(height)){
                hm[height] = node->val;
            }

            if(node->right){
                q.push({node->right,height+1});
            }

            if(node->left){
                q.push({node->left, height+1});
            }
        }

        for(auto i : hm){
            res.push_back(i.second);
        }

        return res;
    }
};