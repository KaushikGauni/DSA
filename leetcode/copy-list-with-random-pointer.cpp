// Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/
// Accepted 2026-10-08 | Runtime 11 ms | Memory 15 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        for(Node* temp = head; temp; temp = temp->next->next){
            Node* c = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = c;
        }

        for(Node* temp = head; temp; temp = temp->next->next){
            if(temp->random)
            temp->next->random = temp->random->next;
        }

        Node* res = head->next;

        for(Node* temp = head; temp;temp=temp->next){
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next){
                copy->next = copy->next->next;
            }
        }

        return res;

    }
};