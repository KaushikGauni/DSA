// Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Accepted 2026-09-26 | Runtime 43 ms | Memory 38.6 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        build(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return parse(ss);    
    }

    void build(TreeNode* root, string &s){
        if(!root){
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        build(root->left, s);
        build(root->right, s);
    }

    TreeNode* parse(stringstream &ss){
        string token;
        getline(ss,token,',');
        if(token == "#") return nullptr;
        
        TreeNode* res = new TreeNode(stoi(token));
        res->left = parse(ss);
        res->right = parse(ss);
        return res;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));