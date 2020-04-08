// Leetcode 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/Runtime: 0 ms
// Runtime: 0 ms
// Memory: 6.4 MB

// using fast-and-slow pointers is faster than this solution
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        int sz = 0;
        ListNode *h = head;
        while (h)
        {
            h = h->next;
            sz++;
        }
        
        h = head;
        int mid = sz / 2;
        int i = 0;
        while (i < mid)
        {
            i++;
            h = h->next;
        }
        
        return h;
    }
};
