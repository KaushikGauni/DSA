// Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Accepted 2026-06-22 | Runtime 55 ms | Memory 23.8 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return nullptr;
        }
        ListNode* a = headA, *b = headB;
        while(a!=b){
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }

        return a;
    }
};