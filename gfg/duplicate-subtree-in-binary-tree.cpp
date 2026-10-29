// Duplicate Subtree Check (Medium)
// https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
// Correct 2026-09-26 14:18:21 | C++

/* Structure of a Tree Node
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
    unordered_map<string,int> hm;
    bool dupSub(Node* root) {
        // code here
        bool found = false;
        solve(root, found);
        return found;
    }
    
    string solve(Node* root, bool &found){
        if(!root){
            return "#";
        }
        string left = solve(root->left, found);
        string right = solve(root->right, found);
        
        string res = to_string(root->data) + "," + left + "," + right;
        
        hm[res]++;
        
        if(hm[res]>=2 && !(left=="#" && right=="#")){
            found = true;
        }
        
        return res;
    }
    
    
};