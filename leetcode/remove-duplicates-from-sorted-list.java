// Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Accepted 2025-07-31 | Runtime 0 ms | Memory 44.5 MB

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null){
            return null;
        }
        if(head.next==null){
            return head;
        }
        ListNode temp = head;
        while(temp.next!=null && temp!=null){
            if(temp.val==temp.next.val){
                temp.next = temp.next.next;
            }
            else{
                temp = temp.next;
            }
        }   
        return head;
    }
}