// Remove Duplicates from Linked List (Easy)
// https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Correct 2026-09-27 10:49:10 | C++

/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(!head){
            return nullptr;
        }
        unordered_set<int> hs;
        Node* curr = head;
        Node* prev = nullptr;
        
        while(curr){
            if(hs.count(curr->data)){
                prev->next = curr->next;
                delete curr;
            }
            else{
                hs.insert(curr->data);
                prev = curr;    
            }
            curr = prev->next;
        }
        
        return head;
    }
};