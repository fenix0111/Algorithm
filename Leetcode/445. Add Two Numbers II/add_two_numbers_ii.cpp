// Leetcode 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
// Runtime: 28ms

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
    ListNode* helper(ListNode* l1, ListNode* l2, int count, int endCount) 
    {
        
        if (l1 && l2)
        {
            if (count < endCount)
            {
                ListNode* retNode = helper(l1->next, l2, count + 1, endCount);
                int sum = l1->val;
                if (retNode && retNode->val > 9)
                {
                    sum++;
                    retNode->val -= 10;
                }
                ListNode* curNode = new ListNode(sum);
                curNode->next = retNode;
                return curNode;
            }
            else
            {
                ListNode* retNode = helper(l1->next, l2->next, count + 1, endCount);
                int sum = l1->val + l2->val;
                if (retNode && retNode->val > 9)
                {
                    sum++;
                    retNode->val -= 10;
                }
                ListNode* curNode = new ListNode(sum);
                curNode->next = retNode;
                return curNode;
            }
        }
        else
        {
            return NULL;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int len1 = 0;
        int len2 = 0;
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        while (h1)
        {
            h1 = h1->next;
            len1++;
        }
        
        while (h2)
        {
            h2 = h2->next;
            len2++;
        }
        
        int diff = abs(len1 - len2);
        
        ListNode *ll = l1;
        ListNode *ss = l2;
        
        if (len1 < len2)
        {
            ll = l2;
            ss = l1;
        }
        
        int c = 0;
        ListNode *ret = new ListNode(-1);
        ret->next = helper(ll, ss, 0, diff);
        
        if (ret->next->val > 9)
        {
            ret->next->val -= 10;
            ListNode *cf = new ListNode(1);
            cf->next = ret->next;
            ret->next = cf;
        }
        
        return ret->next;
    }
};
