// Leetcode 61. Rotate List
// https://leetcode.com/problems/rotate-list/description/
// Runtime: 19ms (very slow...)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == NULL || head->next == NULL)
            return head;

        int len = 0;
        ListNode *h = head;
        while (h)
        {
            len++;
            h = h->next;
        }

        h = head;

        int len_mod = k % len;
        if (len_mod == 0)
            return head;
        
        ListNode *new_head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *new_tail = (ListNode*)malloc(sizeof(ListNode));

        new_head = head;
        new_tail = head;

        for (int i = 0; i < len - len_mod; i++)
        {
            new_head = new_head->next;
        }

        ListNode *before_head = (ListNode*)malloc(sizeof(ListNode));
        before_head = head;
        while (before_head->next)
        {
            before_head = before_head->next;
        }

        for (int i = 0; i < len - len_mod - 1; i++)
        {
            new_tail = new_tail->next;
        }

        new_tail->next = NULL;

        before_head->next = head;
        return new_head;
    }
};
