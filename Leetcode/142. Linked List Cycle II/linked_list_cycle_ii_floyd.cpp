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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (tortoise && hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            
            if (tortoise == NULL || hare == NULL)
            {
                return NULL;
            }
            
            if (tortoise == hare)
            {
                break;
            }
        }
        
        if (tortoise == NULL || hare == NULL || tortoise->next == NULL || hare->next == NULL)
        {
            return NULL;
        }
        
        tortoise = head;
        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        return tortoise;
    }
};
