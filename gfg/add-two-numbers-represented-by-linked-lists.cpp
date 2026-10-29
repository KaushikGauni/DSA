// Add Number Linked Lists (Medium)
// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// Correct 2026-09-29 10:17:32 | C++

/*
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
  
    void insertAtHead(Node* &head, int rem){
        Node *temp = new Node(rem);
        temp->next = head;
        head = temp;
    }
  
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        stack<int> s1, s2;
        Node* temp1 = head1, *temp2 = head2;
        while(temp1){
            s1.push(temp1->data);
            temp1 = temp1->next;
        }
        
        while(temp2){
            s2.push(temp2->data);
            temp2 = temp2->next;
        }
        
        Node* ans = nullptr;
        int carry = 0;
        
        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;
            
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtHead(ans,digit);
        }
        
        while(ans && ans->next && ans->data == 0){
            Node* del = ans;
            ans = ans->next;
            delete del;
        }
        
        return ans;
    }
};