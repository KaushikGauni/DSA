// Reverse Level Order Traversal (Medium)
// https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1
// Correct 2026-09-24 15:12:59 | C++

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right; 
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> res;
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        levels.push_back({root->data});
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            while(s--){
                Node* node = q.front();
                q.pop();
                
                if(node->left){
                    temp.push_back(node->left->data);
                    q.push(node->left);
                }
                
                if(node->right){
                    temp.push_back(node->right->data);
                    q.push(node->right);
                }
            }
            levels.push_back(temp);
        }
        
        reverse(levels.begin(), levels.end());
        
        for(auto arr : levels){
            for(int i : arr){
                res.push_back(i);
            }
        }
        
        return res;
    }
};