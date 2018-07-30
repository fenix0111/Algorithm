// Leetcode 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/
// Runtime: 9ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (l1 && l2 == NULL)
        return l1;

    if (l2 && l1 == NULL)
        return l2;

    if (l1 == NULL && l2 == NULL)
        return NULL;

    head = node;
    while (l1 || l2)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = tmp;
        if (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                tmp->val = l2->val;
                l2 = l2->next;
            }
        }
        else if (l1)
        {
            tmp->val = l1->val;
            l1 = l1->next;
        }
        else if (l2)
        {
            tmp->val = l2->val;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = NULL;
    head = head->next;
    return head;
}

// 3ms参考解法
static struct ListNode *mergeTwoLists_not_null(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head, *last;
    
    if (l1->val < l2->val) 
    {
        last = head = l1;
        l1 = l1->next;
    } 
    else 
    {
        last = head = l2;
        l2 = l2->next;
    }
    
    while (l1 && l2) 
    {
        if (l1->val < l2->val) 
        {
            last->next = l1;
            last = last->next;
            l1 = l1->next;
        } 
        else 
        {
            last->next = l2;
            last = last->next;
            l2 = l2->next;
        }
    }
    
    if (l1) 
    {
        last->next = l1;
    }
    else 
    {
        last->next = l2;
    }
    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;
    return mergeTwoLists_not_null(l1, l2);
}

