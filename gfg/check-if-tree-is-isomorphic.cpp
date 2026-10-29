// Isomorphic Trees (Medium)
// https://www.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
// Correct 2026-09-26 10:08:11 | C++

/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isIsomorphic(Node *root1, Node *root2) {
        // code here
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
    
        bool normal = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right, root2->right);
        bool flipped = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right, root2->left);
    
        return normal || flipped;
    }
};