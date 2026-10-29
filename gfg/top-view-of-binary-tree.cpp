// Top View of Binary Tree (Medium)
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Correct 2026-09-26 13:40:55 | C++

/* 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(!root){
            return {};
        }
        map<int,int> hm;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                Node* node = q.front().second;
                int h = q.front().first;
                q.pop();
                
                if(!hm.count(h)){
                    hm[h] = node->data;
                }
                
                if(node->left){
                    q.push({h-1, node->left});
                }
                
                if(node->right){
                    q.push({h+1, node->right});
                }
            }
        }
        
        vector<int> res;
        
        for(auto a : hm){
            res.push_back(a.second);
        }
        
        return res;
    }
};