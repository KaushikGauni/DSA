// Intersection in Y Shaped Lists (Medium)
// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// Correct 2026-09-27 11:47:30 | C++

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        if(!head1 || !head2){
            return nullptr;
        }
        Node* a = head1, *b = head2;
        
        while(a!=b){
            a = a ? a->next : head2;
            b = b ? b->next : head1;
        }
        
        return b;
    }
};