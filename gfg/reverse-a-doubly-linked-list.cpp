// Reverse a Doubly Linked List (Easy)
// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Correct 2026-09-28 10:18:04 | C++

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head || !head->next){
            return head;
        }
        Node* curr = head;
        Node* temp = nullptr;
        while(curr){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        
        if(temp){
            head = temp->prev;
        }
        
        return head;
    }
};