// Transform to Sum Tree (Easy)
// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1
// Correct 2026-09-26 10:00:34 | C++

/* Structure for Tree Node
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
};
*/

class Solution {
  public:
    void toSumTree(Node *root) {
        // code here
        Sum(root);
    }
    
    int Sum(Node* &root){
        if(!root){
            return 0;
        }
        int oldData = root->data;
        int left = Sum(root->left);
        int right = Sum(root->right);
        
        root->data = left + right;
    
        return oldData + left + right;
    }
};