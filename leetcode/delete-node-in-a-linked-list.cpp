// Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// Accepted 2026-06-16 | Runtime 5 ms | Memory 12.3 MB

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
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};