// Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// Accepted 2026-10-14 | Runtime 11 ms | Memory 13.5 MB

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hs;
        ListNode* curr = head;

        while(curr){
            if(hs.count(curr->next)){
                return curr->next;
            }
            hs.insert(curr);
            curr = curr->next;
        }

        return nullptr;
    }
};