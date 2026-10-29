// Predecessor and Successor in BST (Medium)
// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// Correct 2026-09-02 21:38:14 | C++

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
  
    Node* pred, *succ;
    vector<Node*> arr;
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred = nullptr, *succ = nullptr, *curr = root;
        
        while(curr){
            if(curr->data < key){
                pred = curr;
                curr = curr->right;
            }
            
            else if(curr->data > key){
                succ = curr;
                curr = curr->left;
            }
            
            else{
                if(curr->left){
                    Node* t = curr->left;
                    while(t->right){
                        t = t->right;
                    }
                    pred = t;
                }
                if(curr->right){
                    Node* t = curr->right;
                    while(t->left){
                        t = t->left;
                    }
                    succ = t;
                }
                break;
            }
        }
        
        return {pred,succ};
    }

};