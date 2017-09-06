// Leetcode 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Runtime: 49ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // 用了辅助的map结构，保存每个节点访问次数。若相交则必有一点的访问数大于1.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *na = headA;
        ListNode *nb = headB;
        map<int, int> m;
        while (na)
        {
            map<int, int>::const_iterator cit = m.find(na->val);
            if (cit == m.end())
            {
                m.insert(make_pair(na->val, 1));
            }
            else
            {
                m.insert(make_pair(na->val, 2));
            }
            na = na->next;
        }

        while (nb)
        {
            map<int, int>::const_iterator cit = m.find(nb->val);
            if (cit == m.end())
            {
                m.insert(make_pair(nb->val, 1));
            }
            else
            {
                return nb;
            }
            nb = nb->next;
        }
        return NULL;
    }
    
    // 32ms参考解法
    ListNode *getIntersectionNode_fast(ListNode *headA, ListNode *headB) 
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *currA = headA;
        ListNode *currB = headB;
        while(currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
            if (currA == currB)
                break;
            if (currA == NULL)
                currA = headB;
            if (currB == NULL)
                currB = headA;
        }
        return currA;
    }
};
