// Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Accepted 2026-06-30 | Runtime 0 ms | Memory 37.2 MB

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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushall(root);
    }
    
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        
        if(!reverse)
            pushall(node->right);

        else
            pushall(node->left);

        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root,false);
        BSTIterator right(root,true);
        int i = left.next();
        int j = right.next();

        while(i<j){
            if(i+j == k){
                return true;
            }
            else if(i+j > k){
                j = right.next();
            }
            else{
                i = left.next();
            }
        }

        return false;
    }

    void inorder(vector<int> &nums, TreeNode* root){
        if(!root){
            return;
        }

        inorder(nums,root->left);
        nums.push_back(root->val);
        inorder(nums,root->right);
    }
};