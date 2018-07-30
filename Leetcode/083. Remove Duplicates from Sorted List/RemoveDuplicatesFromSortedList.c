// Leetcode 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Runtime: 6ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node = head;

    if (head == NULL)
        return NULL;
    
    while(node->next)
    {
        if (node->val == node->next->val)
        {
            node->next = node->next->next;       
        }
        else
        {
            node = node->next;
        }
    }
    return head;
}
