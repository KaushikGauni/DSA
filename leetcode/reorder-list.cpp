// Reorder List
// https://leetcode.com/problems/reorder-list/
// Accepted 2026-09-27 | Runtime 0 ms | Memory 22.7 MB

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

    void rev(ListNode* &head){
        if(!head || !head->next){
            return;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    void reorderList(ListNode* head) {
        if(!head){
            return;
        }
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        rev(slow);
        
        ListNode* first = head;
        ListNode* second = slow;


        while(second->next){
            ListNode* n1 = first->next;
            ListNode* n2 = second->next;
            first->next = second;
            second->next = n1;
            first = n1;
            second = n2;
        }
    }
};