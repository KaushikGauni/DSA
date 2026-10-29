// Segregate Evens and Odds in a Linked List (Medium)
// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
// Correct 2026-09-28 11:45:33 | C++

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node evenHead(-1) , oddHead(-1);
        Node *even = &evenHead, *odd = &oddHead;
        Node *temp = head;
        while(temp){
            if(temp->data % 2 ==0){
                even->next = temp;
                even = even->next;
            }
            else{
                odd->next = temp;
                odd = odd->next;
            }
            temp = temp->next;
        }
        
        
        even->next = oddHead.next;
        odd->next = nullptr;
        
        return evenHead.next;
    }
};