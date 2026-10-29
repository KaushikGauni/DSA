// Delete Nodes with Greater on Right (Medium)
// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
// Correct 2026-09-28 11:23:14 | C++

/* Structure of a Linked List node
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
  
    void rev(Node* &head){
        if(!head){
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
    
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        head = prev;
    }
  
    Node *compute(Node *head) {
        // code here
        if(!head || !head->next){
            return head;
        }
        rev(head);
        Node* curr = head;
        int maxi = curr->data;
        while(curr && curr->next){
            if(curr->next->data < maxi){
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
            }
            else{
                maxi = curr->next->data;
                curr = curr->next;
            }
        }
        
        rev(head);
        return head;
    }
};