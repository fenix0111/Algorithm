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

// O(1) space complexity
// main logic is same as merge sort
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        
        ListNode* head = new ListNode(-1);
        head->next = lists[0];
        ListNode* prev = new ListNode(-1);
        ListNode* follow = new ListNode(-1);
        
        for (int i = 1; i < lists.size(); i++)
        {
            prev = head->next;
            follow = lists[i];
            if (follow == nullptr)
            {
                continue;
            }
            
            if (prev == nullptr)
            {
                head->next = follow;
                continue;
            }
            
            // redirect head->next to node with less value
            if (prev->val <= follow->val)
            {
                head->next = prev;
            }
            else
            {
                head->next = follow;
            }
            
            ListNode* p = head;
            
            while (prev && follow)
            {
                if (prev->val <= follow->val)
                {
                    p->next = prev;
                    prev = prev->next;
                }
                else
                {
                    p->next = follow;
                    follow = follow->next;
                }
                p = p->next;
            }
            
            while (prev)
            {
                p->next = prev;
                p = p->next;
                prev = prev->next;
            }
            
            while (follow)
            {
                p->next = follow;
                p = p->next;
                follow = follow->next;
            }
        }
        
        return head->next;
    }
};
