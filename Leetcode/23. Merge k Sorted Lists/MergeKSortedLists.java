// Leetcode 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/
// Runtime: 115ms (very slow...)

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
 // the solution was not polished and very naive, even used bubble sort
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (null == lists || lists.length == 0) {
            return null;
        }

        // for head
        ListNode head = null;

        // for connecting all chains
        ListNode conn = new ListNode(-1);
        for (int i = 0; i < lists.length; i++) {
            // check the empty chain
            if (lists[i] == null) {
                continue;
            }

            if (head == null) {
                head = lists[i];
            }

            conn.next = lists[i];
            while (null != conn.next) {
                conn = conn.next;
            }
        }

        ListNode rear = head; // i
        ListNode front = null; // i+1

        while (null != rear) {
            front = rear.next;
            while (null != front) {
                if (rear.val > front.val) {
                    int temp = rear.val;
                    rear.val = front.val;
                    front.val = temp;
                }
                front = front.next;
            }
            rear = rear.next;
        }

        return head;
    }
}
