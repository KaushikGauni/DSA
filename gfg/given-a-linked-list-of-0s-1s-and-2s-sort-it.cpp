// Sort Llinked List of 0s, 1s and 2s (Medium)
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Correct 2026-09-27 11:04:56 | C++

/* Node is defined as
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
    Node* segregate(Node* head) {
        // code here
        int  zeroes = 0, ones = 0, twos = 0;
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0){
                zeroes++;
            }
            else if(temp->data == 1){
                ones++;
            }
            else{
                twos++;
            }
            
            temp = temp->next;
        }
        
        Node res(-1);
        Node* dummy = &res;
        
        for(int i=0;i<zeroes;i++){
            dummy->next = new Node(0);
            dummy = dummy->next;
        }
        
        for(int i=0;i<ones;i++){
            dummy->next = new Node(1);
            dummy = dummy->next;
        }
        
        for(int i=0;i<twos;i++){
            dummy->next = new Node(2);
            dummy = dummy->next;
        }
        
        return res.next;
    }
};