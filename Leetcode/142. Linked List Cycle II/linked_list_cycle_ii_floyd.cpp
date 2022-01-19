/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// let the length of cycle(if it exists) be C
// distance between head and the entry of cycle be X
// distance between the entry of cycle and meet point of tortoise and hare be Y
// distance from meet point to entry of cycle be Z

// head------------------------entry------------meet point
//                              |                   |
//                              |       cycle       |
//                              |                   |
//                              |                   |
//                              ---------------------

// we have C = Y + Z
// since hare has double walk speed of tortoise
// therefore 2(X + Y) = X + C*n + Y 
//        => X + Y = n*(Y + Z)
//        => X = n*(Y + Z) - Y
//        => X = (n - 1)*Y + (n - 1)*Z + Z
//        => X = (n - 1)*C + Z
// here, (n - 1)*C means walked the cycle several times
// we could conclude that X = Z

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
