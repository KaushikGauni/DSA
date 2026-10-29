// Replace with Least Greater on Right (Medium)
// https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1
// Correct 2026-09-16 11:04:28 | C++

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class Solution {
  public:
  
    int insert(TreeNode* &root, int i){
        if(!root){
            root = new TreeNode(i);
            return -1;
        }
        
        int ans = -1;
        
        if(i<root->val){
            ans = root->val;
            int temp = insert(root->left, i);
            if(temp!=-1){
                ans = temp;
            }
        }
        else{
            ans = insert(root->right, i);
        }
        return ans;
    }
  
    vector<int> findLeastGreater(vector<int>& arr) {
        // code here
        TreeNode* root = nullptr;
        int n = arr.size();
        vector<int> res(n,-1);
        for(int i=n-1;i>=0;i--){
            res[i] = insert(root,arr[i]);
        }
        return res;
    }
};