// Zig-Zag Tree Traversal (Medium)
// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// Correct 2026-09-25 12:21:15 | C++

/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        bool rtl = false;
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i=0;i<s;i++){
                Node* node = q.front();
                q.pop();
                int idx = i;
                if(rtl){
                    idx = s - i - 1;
                }
                temp[idx] = node->data;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            for(int i : temp){
                res.push_back(i);
            }
            rtl = !rtl;
        }
        
        return res;
    }
};