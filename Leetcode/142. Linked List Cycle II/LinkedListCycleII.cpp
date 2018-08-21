// Leetcode 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/description/
// Runtime: 12ms

// using set to check first repeated memory address
// next step: solving it without using extra space

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head) {
            return head;
        }
        
        ListNode *h = head;
        set<ListNode*> ss;
        
        while (h) {
            if (ss.find(h) == ss.end()) {
                ss.insert(h);
                h = h->next;
            } else {
                return h;
            }
        }
        
        return NULL;
    }
};
