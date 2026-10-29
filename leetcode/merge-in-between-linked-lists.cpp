// Merge In Between Linked Lists
// https://leetcode.com/problems/merge-in-between-linked-lists/
// Accepted 2026-07-28 | Runtime 194 ms | Memory 99.4 MB

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        for(int i=0;i<a-1;i++){
            prev = prev->next;
        }

        ListNode* after = prev;
        for(int i=0;i<(b-a+2);i++){
            after = after->next;
        }
        prev->next = list2;
        ListNode* tail = list2;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = after;

        return list1;
    }
};