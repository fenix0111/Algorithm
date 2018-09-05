// Leetcode 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/description/
// Runtime: 24ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // traverse the linked list reversely by recursion
class Solution {
public:
    ListNode* palinHelper(ListNode* h, ListNode* r)
    {
        ListNode *ret = NULL;
        if (r->next)
        {
            ret = palinHelper(h, r->next);
            if (NULL == ret)
            {
                return NULL;
            }
            else 
            {
                if (ret->val != r->val)
                {
                    return NULL;
                }
            
                return ret->next;
            }
        }
        else
        {
            if (h->val == r->val)
            {
                return h->next;
            }
            else
            {
                return NULL;
            }
        }
        
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        
        ListNode *h = head;
        ListNode *r = head;
        
        if (NULL == palinHelper(h, r->next))
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
};
