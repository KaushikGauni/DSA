// Delete Node Without Linked List Head (Medium)
// https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1
// Correct 2026-09-27 10:40:21 | C++

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void deleteNode(Node* x) {
        // code here
        if(!x->next){
            delete x;
            return;
        }
        
        x->data = x->next->data;
        
        Node* temp = x->next;
        x->next = x->next->next;
        delete temp;
        
    }
};