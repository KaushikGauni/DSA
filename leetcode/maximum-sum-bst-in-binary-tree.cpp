// Maximum Sum BST in Binary Tree
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Accepted 2026-06-30 | Runtime 1250 ms | Memory 111.5 MB

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

struct Node{
    int maxValue;
    int minValue;
    int sum;
    bool isBST;
};

class Solution {
public:
    int ans = 0;
    int maxSumBST(TreeNode* root) {
        if(!root){
            return 0;
        }
        sum(root);

        return ans;
    }

    Node sum(TreeNode* root){
        if(!root){
            return {INT_MIN,INT_MAX,0,true};
        }
        Node left = sum(root->left);
        Node right = sum(root->right);
        Node result;
        if(left.isBST && right.isBST && left.maxValue < root->val && root->val < right.minValue){
            result.isBST = true;
            result.sum = root->val + left.sum + right.sum;
            result.maxValue = max(root->val, right.maxValue);
            result.minValue = min(root->val, left.minValue);
            ans = max(ans, result.sum);
        }
        else{
            result.isBST = false;
            result.sum = 0;
            result.maxValue = INT_MAX;
            result.minValue = INT_MIN;
        }

        return result;
    }
};