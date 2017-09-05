/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
// Leetcode 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Runtime: 5ms
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null) {
            return head;
        }

        if (head.next == null) {
            return head;
        }

        ListNode res = head.next;
        ListNode p1 = head;
        ListNode p2 = head.next;
        ListNode tail = null;

        while ((p1 != null) && (p2 != null)) {
            p1.next = p2.next;
            p2.next = p1;

            if (tail != null) {
                tail.next = p2;
            }

            tail = p1;

            if (p2 != null) {
                if (p2.next != null) {
                    p1 = p2.next.next;
                }
            }

            if (p1 != null) {
                p2 = p1.next;
            }

        }

        return res;
    }
}
