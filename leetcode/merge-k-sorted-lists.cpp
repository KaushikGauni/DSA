// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
// Accepted 2026-09-29 | Runtime 2 ms | Memory 18.8 MB

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(ListNode* l : lists){
            if(l)
            pq.push({l->val,l});
        }

        ListNode res(0);
        ListNode* dummy = &res;

        while(!pq.empty()){
            ListNode* l = pq.top().second;
            int x = pq.top().first;
            pq.pop();

            dummy->next = l;
            dummy = dummy->next;
            if(l->next){
                pq.push({l->next->val, l->next});
            }
        }

        return res.next;
    }
};