// Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Accepted 2026-10-14 | Runtime 5 ms | Memory 11.7 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    void add(Node* &dummy, Node* curr){
        if(!curr) return;

        Node* next = curr->next;
        Node* child = curr->child;

        dummy->next = curr;
        curr->prev = dummy;
        dummy = curr;

        curr->child = nullptr;

        add(dummy,child);
        add(dummy,next);
    }

    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node res;
        res.next = nullptr;
        Node* dummy = &res;
        Node* curr = head;
        add(dummy,curr);

        res.next->prev = nullptr;
        dummy->next = nullptr;

        return res.next;
    }
};