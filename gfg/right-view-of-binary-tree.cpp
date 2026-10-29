// Right View of Binary Tree (Easy)
// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Correct 2026-09-25 10:48:41 | C++

/*
Definition for Node
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
    vector<int> rightView(Node *root) {
        //  code here
        if(!root){
                    return {};
                }

                map<int,Node*> hm;
                queue<pair<int,Node*>> q;
                q.push({0,root});
                hm[0] = root;


                while(!q.empty()){
                    int s = q.size();
                    while(s--){
                        Node* node = q.front().second;
                        int height = q.front().first;
                        q.pop();

                        if(!hm.count(height)){
                            hm[height] = node;
                        }
                        
                        if(node->right){
                            q.push({height+1,node->right});
                        }
                        
                        if(node->left){
                            q.push({height+1,node->left});
                        }

                        

                    }
                }

                vector<int> res;

                for(auto i : hm){
                    res.push_back(i.second->data);
                }

                return res;
    }
};