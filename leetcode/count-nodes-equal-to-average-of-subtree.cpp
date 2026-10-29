// Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Accepted 2026-09-11 | Runtime 0 ms | Memory 15.9 MB

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
    int count = 0;
    int averageOfSubtree(TreeNode* root) {
        averageSub(root); 
        return count;
    }


    pair<int,int> averageSub(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto left = averageSub(root->left);
        auto right = averageSub(root->right);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if(sum/nodes == root->val){
            count++;
        }

        return {sum,nodes};
    }
};