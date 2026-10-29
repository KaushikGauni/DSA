// Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Accepted 2026-08-31 | Runtime 0 ms | Memory 124.7 MB

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1, prevCritical=-1, last=-1;
        int i = 1;
        int minDistance = INT_MAX, maxDistance = INT_MIN;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr && curr->next){
            if((prev->val<curr->val && curr->next->val<curr->val) || (prev->val>curr->val && curr->next->val>curr->val)){
                if(first==-1){
                    first=i;
                }
                if(prevCritical!=-1){
                    minDistance = min(minDistance, i - prevCritical);
                }
                prevCritical = i;
                maxDistance = i - first;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        if(first==-1 || first==prevCritical){
            return {-1,-1};
        }

        return {minDistance,maxDistance};
    }
};