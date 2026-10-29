// Height of Binary Tree (Easy)
// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
// Correct 2026-08-31 13:09:43 | C++

/* Structrue of Binary Tree Node
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
    int height(Node* root) {
        // code here
        if(!root){
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
        // return calc_heights(root,0);
    }
    
    // int calc_heights(Node* root, int height){
    //     if(!root){
    //         return height;
    //     }
    //     return max(calc_heights(root->left,height+1), calc_heights(root->right, height+1));
    // }
};