// Kth Largest in BST (Easy)
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// Correct 2026-09-03 15:24:13 | C++

/* Structure of a Binary Tree Node
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
  
    void solve(Node* root, int &count, int &k, int &ans){
        if(!root){
            return;
        }
        solve(root->right, count, k, ans);
        if(count >= k){
            return;
        }
        count++;
        if(count == k){
            ans = root->data;
            return;
        }
        solve(root->left, count, k, ans);
    }
  
    int kthLargest(Node *root, int k) {
        // code here
        int count = 0, ans = -1;
        solve(root,count,k,ans);
        return ans;
    }
    
};