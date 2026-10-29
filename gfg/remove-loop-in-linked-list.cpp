// Remove Cycle in Linked List (Medium)
// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Correct 2026-10-04 10:38:28 | C++

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        unordered_set<Node*> hs;
        Node* temp = head;
        
        while(temp){
            if(hs.count(temp->next)){
                temp->next = nullptr;
                break;
            }
            else{
                hs.insert(temp);
            }
            temp = temp->next;
        }
    }
};