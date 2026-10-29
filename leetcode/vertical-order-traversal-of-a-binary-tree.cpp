// Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Accepted 2026-06-27 | Runtime 3 ms | Memory 15.8 MB

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> res;
        map<int, map<int,multiset<int>>> hm;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();

            hm[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{col-1,row+1}});
            }

            if(node->right){
                q.push({node->right,{col+1,row+1}});
            }
        } 

        for(auto &a : hm){
            vector<int> temp;
            for(auto &b : a.second){
                temp.insert(temp.end(),b.second.begin(), b.second.end());
            }
            res.push_back(temp);
        }

        return res;
    }
};