// Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
// Accepted 2025-11-28 | Runtime 0 ms | Memory 118 MB

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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast){
            slow = slow->next;
        }
        ListNode* first = head;
        ListNode* second = reverseList(slow);

        while(second){
            if(first->val!=second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};