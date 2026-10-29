// Bottom View of Binary Tree (Medium)
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Correct 2026-09-26 13:41:36 | C++

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
    vector<int> bottomView(Node *root) {
        // code here
        if(!root){
                    return {};
                }
                map<int,int> hm;
                queue<pair<int,Node*>> q;
                q.push({0,root});

                while(!q.empty()){
                    int s = q.size();
                    while(s--){
                        Node* node = q.front().second;
                        int h = q.front().first;
                        q.pop();


                        hm[h] = node->data;

                        if(node->left){
                            q.push({h-1, node->left});
                        }

                        if(node->right){
                            q.push({h+1, node->right});
                        }
                    }
                }

                vector<int> res;

                for(auto a : hm){
                    res.push_back(a.second);
                }

                return res;
    }
};