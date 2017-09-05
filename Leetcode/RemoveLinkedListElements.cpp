/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/
// Runtime: 26ms

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *ret = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        ListNode *follow = (ListNode*)malloc(sizeof(ListNode));
        p = head;
        follow = head;
        ret = head;

        if (head == NULL)
        {
            return head;
        }

        while (ret)
        {
            if (ret->val == val)
            {
                ret = ret->next;
            }
            else
            {
                break;
            }
        }

        while (p)
        {
            if (p->val == val)
            {
                follow->next = p->next;
                free(p);
                p = follow->next;
                continue;
            }
            follow = p;
            p = p->next;
        }
        return ret;
    }
};
