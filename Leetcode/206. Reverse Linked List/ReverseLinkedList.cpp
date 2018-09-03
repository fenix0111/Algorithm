// Leetcode 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/
// Runtime: 4ms

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
    ListNode* rlHelper(ListNode *node, ListNode **res) {
        if (node == NULL) {
            return node;
        }
        if (node->next == NULL) {
            *res = node;
        }
        
        ListNode* r = rlHelper(node->next, res);
        if (r) {
            r->next = node;
        }
        
        return node;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *res = NULL;
        
        ListNode* r = rlHelper(head, &res);
        r->next = NULL;
        
        return res;
    }
};
