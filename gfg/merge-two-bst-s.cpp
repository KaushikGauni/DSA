// Merge Two BSTs (Medium)
// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
// Correct 2026-10-13 15:07:33 | C++

/* Structure of a Binary Search Tree node
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
  
    void inorder(Node* root, vector<int>& arr){
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
  
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        stack<Node*> s1, s2;
        vector<int> res;
        while(r1 || r2 || !s1.empty() || !s2.empty()){
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
            
            if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)){
                Node* temp = s1.top();
                s1.pop();
                
                res.push_back(temp->data);
                r1 = temp->right;
            }
            
            else{
                Node* temp = s2.top();
                s2.pop();
                
                res.push_back(temp->data);
                r2 = temp->right;
            }
            
        }
        
        return res;
    }
};