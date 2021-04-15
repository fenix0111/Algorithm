// Leetcode 86. Partition List
// https://leetcode.com/problems/partition-list/description/
// time complexity: O(n)
// space complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode* greaterHead = new ListNode(-1);
        ListNode* lessHead = new ListNode(-1);
        
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        ListNode* node = head;        
        
        while (node)
        {
            if (node->val < x)
            {
                less->next = node;
                less = node;     
            }
            else
            {
                greater->next = node;
                greater = node;
            }
            
            node = node->next;
        }
        
        greater->next = NULL;
        less->next = greaterHead->next;
            
        return lessHead->next;
        
    }
};
