// Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/
// Accepted 2026-06-19 | Runtime 0 ms | Memory 15.4 MB

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* eventemp = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;

        }
        odd->next = eventemp;
        return head;
    }
};