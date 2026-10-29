// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
// Accepted 2025-08-09 | Runtime 0 ms | Memory 42.5 MB

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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode temp1 = list1;
        ListNode temp2 = list2;
        ListNode res = new ListNode();
        ListNode res2 = res;
        while(temp1!=null && temp2!=null){
            if(temp1.val <= temp2.val){
                res.next = temp1;
                temp1 = temp1.next;
            }
            else{
                res.next = temp2;
                temp2 = temp2.next;
            }
            res = res.next;
        }
        res.next = temp1==null ? temp2 : temp1;

        return res2.next;
    }
}