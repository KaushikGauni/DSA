// Clone Graph
// https://leetcode.com/problems/clone-graph/
// Accepted 2026-09-13 | Runtime 7 ms | Memory 12 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hm;

    Node* dfs(Node* node){
        if(node == nullptr){
            return nullptr;
        }

        if(hm.count(node)){
            return hm[node];
        }

        Node* clone = new Node(node->val);
        hm[node] = clone;

        for(Node* neigh : node->neighbors){
            clone->neighbors.push_back(dfs(neigh));
        }

        return clone;
    }


    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};