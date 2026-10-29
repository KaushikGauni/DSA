// All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Accepted 2026-06-28 | Runtime 9 ms | Memory 15.5 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void makeParents(TreeNode* root){
        if(!root){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeParents(root);
        vector<int> res;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        while(!q.empty()){
            if(k==0){
                break;
            }
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent.count(node) && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            k--;
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};