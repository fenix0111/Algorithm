// Leetcode 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
// Runtime: 96ms (very slow)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // need pointer to head of linked list
 // don't let linked list broken
class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if (!head)
            return NULL;
        
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        
        ListNode *current = head->next;
        ListNode *next;
        ListNode *prev = head;
        
        while (current)
        {
            next = current->next;
            
            ListNode *comp = newhead->next;
            ListNode *follow = newhead;
            
            while (comp != current && comp->val <= current->val)
            {
                comp = comp->next;
                follow = follow->next;
            }
            
            follow->next = current;
            current->next = comp;
            prev = comp;
            while (prev && prev->next != current)
            {
                prev = prev->next;
            }
            
            prev->next = next;
            
            if (newhead->next->val > current->val)
            {
                newhead->next = current;
            }
            
            current = next;
        }
        
        return newhead->next;
    }
};
