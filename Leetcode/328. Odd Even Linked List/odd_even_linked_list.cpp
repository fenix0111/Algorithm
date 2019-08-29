// Leetcode 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/
// Runtime: 12ms

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return head;
        }
        
        ListNode *even_head = head->next;
        ListNode *even_node = head->next;
        ListNode *odd_node = head;
        
        while (even_node && even_node->next)
        {
            odd_node->next = even_node->next;
            odd_node = odd_node->next;
            even_node->next = odd_node->next;
            even_node = even_node->next;
        }
        
        odd_node->next = even_head;
        return head;
    }
};
