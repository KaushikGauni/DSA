// Partition List
// https://leetcode.com/problems/partition-list/
// Accepted 2025-08-02 | Runtime 0 ms | Memory 42.4 MB

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode left = new ListNode();
        ListNode right = new ListNode();
        ListNode temp = head;
        ListNode res = left;
        ListNode a = right;
        while(temp!=null){
            if(temp.val<x){
                left.next = temp;
                left = left.next;
            }
            else if(temp.val>=x){
                right.next = temp;
                right = right.next;
            }
            temp = temp.next;
        }

        left.next = a.next;
        right.next =null;

        return res.next;
    }
}