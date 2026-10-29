// Merge Sort for Linked List (Medium)
// https://www.geeksforgeeks.org/problems/sort-a-linked-list/1
// Correct 2026-09-29 10:00:20 | C++

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
  
    Node* merge(Node* left, Node* right){
        Node dummy(-1);
        Node* temp = &dummy;
        
        while(left && right){
            if(left->data <= right->data){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        
        if(left){
            temp->next = left;
        }
        else{
            temp->next = right;
        }
        
        return dummy.next;
    }
  
  
    Node* mergeSort(Node* head) {
        // code here
        
        if(!head || !head->next){
            return head;
        } 
        
        Node* slow = head, *fast = head->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        Node* rightHead = slow->next;
        slow->next = nullptr;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        
        return merge(left,right);
    }
};