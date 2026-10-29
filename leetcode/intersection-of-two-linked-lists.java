// Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Accepted 2023-07-15 | Runtime 1 ms | Memory 46.8 MB

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA==null || headB==null){
            return null;
        }
        ListNode temp1 = headA;
        ListNode temp2 = headB;
        while(temp1!=temp2){
            temp1 = temp1 == null ? headB : temp1.next;
            temp2 = temp2 == null ? headA : temp2.next;
        }

        return temp1;
    }
}