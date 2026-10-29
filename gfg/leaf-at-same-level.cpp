// Leaves at Same Level or Not (Easy)
// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
// Correct 2026-09-25 12:43:31 | C++

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
    vector<int> res;
    
    bool checkp(Node* root, int height, int &leafHeight){
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            if(leafHeight == -1)
                leafHeight = height;
            return leafHeight == height;
        }
        return checkp(root->left, height+1, leafHeight) && checkp(root->right, height+1, leafHeight);
    }
    
    bool check(Node* root) {
        // code here
        if(!root){
            return true;
        }
        int leafHeight = -1;
        return checkp(root,0,leafHeight);
        
    }
};