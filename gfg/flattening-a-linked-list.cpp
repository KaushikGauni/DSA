// Flatten Linked List (Medium)
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Correct 2026-10-01 10:25:12 | C++

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    Node* flatten(Node* head) {
        // code here
        priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
        Node* temp = head;
        
        Node res(-1);
        Node* dummy = &res;
        
        pq.push({temp->data, temp});
        
        while(!pq.empty()){
            Node* node = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            
            dummy->bottom = node;
            dummy = dummy->bottom;
            
            if(node->next){
                pq.push({node->next->data, node->next});
            }
            
            if(node->bottom){
                pq.push({node->bottom->data, node->bottom});
            }
        }
        
        return res.bottom;
    }
};