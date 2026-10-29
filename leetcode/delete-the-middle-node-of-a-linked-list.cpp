// Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 311.9 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return nullptr;
        }
        ListNode *fast = head, *slow = head;
        ListNode *slowprev = nullptr;
        while(fast && fast->next){
            slowprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow){
            ListNode* del = slow;
            slowprev->next = slow->next;
            delete del;
        }

        return head;
    }
};