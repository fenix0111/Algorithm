// Leetcode 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
// Runtime: 24ms

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int len = 0;
        int len1 = 0;
        int len2 = 0;
        bool cf = false;
        
        ListNode *ln1 = l1;
        ListNode *ln2 = l2;
        
        ln1 = l1;
        ln2 = l2;
        vector<int> tbl;
        while (ln1 && ln2)
        {
            int sum = ln1->val + ln2->val;
            if (cf)
            {
                sum++;
            }
            
            if (sum > 9)
            {
                sum = sum % 10;
                cf = true;
            }
            else
            {
                cf = false;
            }
            
            tbl.push_back(sum);
            ln1 = ln1->next;
            ln2 = ln2->next;
        }
        
        while (ln1)
        {
            int sum = ln1->val;
            if (cf)
            {
                sum++;
            }
            
            if (sum > 9)
            {
                sum = sum % 10;
                cf = true;
            }
            else
            {
                cf = false;
            }
            tbl.push_back(sum);
            ln1 = ln1->next;
        }
        
        while (ln2)
        {
            int sum = ln2->val;
            if (cf)
            {
                sum++;
            }
            
            if (sum > 9)
            {
                sum = sum % 10;
                cf = true;
            }
            else
            {
                cf = false;
            }
            tbl.push_back(sum);
            ln2 = ln2->next;
        }
        
        if (cf)
        {
            tbl.push_back(1);
        }
        
        len = tbl.size();
        
        ListNode *head = new ListNode(tbl[0]);
        ListNode *ret = head;
        for (int i = 1; i < len; i++)
        {
            ListNode *node = new ListNode(tbl[i]);
            head->next = node;
            head = node;
        }
        
        return ret;
    }
};
