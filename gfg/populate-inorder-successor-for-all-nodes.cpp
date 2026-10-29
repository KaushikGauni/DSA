// Populate Inorder Successors (Medium)
// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
// Correct 2026-09-15 14:58:18 | C++

/* Binary Tree Node Structure
class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  
  
    void inorder(Node* root, Node* &prev) {
            if (!root) return;

            inorder(root->left, prev);

            if (prev) prev->next = root;
            prev = root;

            inorder(root->right, prev);
        }

        void populateNext(Node *root) {
            Node* prev = nullptr;
            inorder(root, prev);
        }
};