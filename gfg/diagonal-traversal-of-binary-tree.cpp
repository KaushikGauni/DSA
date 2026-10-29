// Diagonal Tree Traversal (Medium)
// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// Correct 2026-09-26 13:50:36 | C++

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        if(!root){
            return {};
        }
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            while(node){
                res.push_back(node->data);
                if(node->left) q.push(node->left);
                node = node->right;
            }
        }
        
        return res;
    }
};