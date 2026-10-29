// Tree Boundary Traversal (Medium)
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Correct 2026-09-02 15:04:26 | C++

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    bool isLeaf(Node *root){
        return root && !root->left && !root->right;
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root){
            return res;
        }
        if(!isLeaf(root))
        res.push_back(root->data);
        leftbound(root->left, res);
        leafBound(root, res);
        vector<int> temp;
        rightBound(root->right, temp);
        reverse(temp.begin(), temp.end());
        for(int i : temp){
            res.push_back(i);
        }
        
        return res;
    }
    
    void leftbound(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        Node* temp = root;
        while(temp){
            if(!isLeaf(temp)){
                res.push_back(temp->data);
            }
            if(temp->left){
                temp = temp->left;
            }
            else if(temp->right){
                temp = temp->right;
            }
            else{
                break;
            }
        }
    }
    
    void leafBound(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        leafBound(root->left, res);
        leafBound(root->right, res);
    }
    
    void rightBound(Node* root, vector<int> &res){
        if(!root){
            return;
        }
        
        Node* temp = root;
        while(temp){
            if(!isLeaf(temp)){
                res.push_back(temp->data);
            }
            
            if(temp->right){
                temp = temp->right;
            }
            
            else if(temp->left){
                temp = temp->left;
            }
            else{
                break;
            }
        }
    }
};