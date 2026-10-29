// Sort List
// https://leetcode.com/problems/sort-list/
// Accepted 2026-06-19 | Runtime 5 ms | Memory 57.1 MB

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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        while(left){
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        
        while(right){
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);

    }
};