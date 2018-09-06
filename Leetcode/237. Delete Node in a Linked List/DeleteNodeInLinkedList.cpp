// Leetcode 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// Runtime: 12ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// assign node the next node value, then make node->next to point to node->next->next
// personally I don't like this problem. the value in the node should not be modified if possible.
class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
