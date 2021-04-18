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

// one pass solution
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* node = head;
        ListNode* follow = new ListNode(-1);
        follow->next = head;
        
        int num = n;
        while (num > 0)
        {
            num--;
            node = node->next;
        }
        
        while (node)
        {
            follow = follow->next;
            node = node->next;
        }
        
        // if first node need to be removed
        if (head == follow->next)
        {
            head = follow->next->next;
        }
        
        follow->next = follow->next->next;
        
        return head;
    }
};
