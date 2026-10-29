// Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// Accepted 2023-07-19 | Runtime 3 ms | Memory 43.3 MB

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
    public ListNode detectCycle(ListNode head) {
        HashSet<ListNode> hs = new HashSet<>();
        while(head!=null){
            if(hs.contains(head)){
                return head;
            }
            hs.add(head);
            head = head.next;
        }
        return null;
    }
}