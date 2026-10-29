// Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
// Accepted 2025-07-31 | Runtime 1 ms | Memory 45.5 MB

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
    public ListNode removeElements(ListNode head, int val) {
        ListNode temp = head;
        if(head==null){
            return null;
        }   
        while(temp.next!=null && temp!=null){
            if(temp.next.val==val){
                temp.next = temp.next.next;
            }
            else{
                temp = temp.next;
            }
        }
        if(head.val==val){
            head = head.next;
        }
        return head;
    }
}