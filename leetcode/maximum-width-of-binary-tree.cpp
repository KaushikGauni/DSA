// Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/
// Accepted 2026-06-27 | Runtime 0 ms | Memory 19.9 MB

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int s = q.size();
            long long first, last;
            long long mini = q.front().second;
            for(int i=0;i<s;i++){
                TreeNode* node = q.front().first;
                long long index = q.front().second - mini;
                q.pop();
                if(i==0){
                    first = index;
                }

                if(i==s-1){
                    last = index;
                }

                if(node->left){
                    q.push({node->left,2*index+1});
                }

                if(node->right){
                    q.push({node->right,2*index+2});
                }

            }

            ans = max(ans, (last-first+1));
        }
        return ans;
    }
};