// Clone List with Next and Random (Hard)
// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// Correct 2026-10-01 11:05:09 | C++

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if(!head){
            return nullptr;
        }
        
        for(Node* t = head; t; t = t->next->next){
            Node* copy = new Node(t->data);
            copy->next = t->next;
            t->next = copy;
        }
        
        for(Node* t = head; t; t = t->next->next){
            if(t->random){
                t->next->random = t->random->next;
            }
        }
        
        Node* newHead = head->next;
        
        for(Node* t = head; t; t = t->next){
            Node* copy = t->next;
            t->next = copy->next;
            if(copy->next){
                copy->next = copy->next->next;
            }
        }
        
        
        return newHead;
    }
};