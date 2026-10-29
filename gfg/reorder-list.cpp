// Reorder List (Hard)
// https://www.geeksforgeeks.org/problems/reorder-list/1
// Correct 2026-09-28 11:53:08 | C++

/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
  
    void rev(Node* &head){
        if(!head || !head->next){
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        head = prev;
    }
  
    void reorderList(Node* head) {
        // code here
        Node* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        rev(slow);
        
        Node* first = head, *second = slow;
    
        while(second->next){
            Node* n1 = first->next;
            Node* n2 = second->next;
        
            first->next = second;
            first = n1;
            second->next = n1;
            second = n2;
        }
        
        return;
    }
};