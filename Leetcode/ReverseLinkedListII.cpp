// Leetcode 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/description/
// Runtime: 3ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // 头指针处理依然是个棘手的问题
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if (head == NULL)
            return head;
   
        if (head->next == NULL)
            return head;
    
        if (m == n)
            return head;
    
        ListNode *pivot = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        ListNode *r = (ListNode*)malloc(sizeof(ListNode));

        pivot->next = head;
        int begin = 1;
        while (begin < m)
        {
            pivot = pivot->next;
            begin++;
        }
   
        begin = m;
        p = pivot->next;
        q = p->next;
        r = q->next;
    
        while (begin < n)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            if (r)
                r = r->next;
            begin++;
        }
    
        pivot->next->next = q;
        pivot->next = p;
    
        // 注意返回的指针变量
        // 当m为1时要跟着头指针走
        if (m == 1)
            return p;
        else
            return head;
    }
};
