// Leetcode 86. Partition List
// https://leetcode.com/problems/partition-list/description/
// Runtime: 6ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
        return head;
    
    ListNode *front = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    ListNode *follow = (ListNode*)malloc(sizeof(ListNode));
    ListNode *phead = (ListNode*)malloc(sizeof(ListNode));
    
    front->next = head;
    cur = head->next;
    follow = head;
    phead->next = head;
    
    while (cur)
    {
        while (front->next)
        {
            if (front->next->val < x)
            {
                front = front->next;
            }
            else
            {
                break;
            }
        }
        
        follow = front;
        cur = front->next;
        
        while (cur)
        {
            if (cur->val >= x)
            {
                cur = cur->next;
                follow = follow->next;
            }
            else
            {
                if (cur->val < x)
                {
                    if (follow == front)
                    {
                        follow->next = cur->next;
                        cur->next = follow;
                        front = cur;
                        cur = follow->next;
                        front = front->next;
                    }
                    else
                    {
                        follow->next = cur->next;
                        cur->next = front->next;
                        if (cur->next == head)
                        {
                            head = cur;
                        }
                        front->next = cur;
                        front = front->next;
                        cur = follow->next;
                    }
                }
            }
        }
    }
    return head;
    }
};
