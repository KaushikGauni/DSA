// Preorder to BST (Medium)
// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1
// Correct 2026-09-16 11:09:09 | C++

/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public: 
  
    Node* build(vector<int>& pre, int &i, int bound){
        if(i>=pre.size() || pre[i]>bound){
            return nullptr;
        }
        Node* res = new Node(pre[i++]);
        res->left = build(pre,i,res->data);
        res->right = build(pre,i,bound);
        
        return res;
    }
  
    Node* preToBST(vector<int>& pre) {
        // code here
        int i = 0, bound = INT_MAX;
        return build(pre,i,bound);
    }
};