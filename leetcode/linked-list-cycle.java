// Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// Accepted 2025-08-10 | Runtime 0 ms | Memory 44.9 MB

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode one = head;
        ListNode two = head;
        while(two!=null && two.next!=null){
            one = one.next;
            two = two.next.next;
            if(one==two) return true;
        }

        return false;
    }
}