// Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Accepted 2026-09-27 | Runtime 0 ms | Memory 14.9 MB

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head, *puk = head;
        for(int i=0;i<n;i++){
            temp = temp->next;
        }
        if(!temp){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(temp->next){
            temp = temp->next;
            puk = puk->next;
        }
        ListNode* del = puk->next;
        puk->next = del->next;
        delete del;

        return head;
    }
};