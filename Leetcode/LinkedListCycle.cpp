// Leetcode 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/
// Runtime: 9ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 两个指针，一个两步一个一步，若有环则必相见（内存地址相同）
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        
        ListNode * two = head->next;
        ListNode * one = head;
        while (one)
        {
            if (one == two)
                return true;
            one = one->next;
            if (two)
            {
                two = two->next;
                if (two)
                {
                    two = two->next;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            
        }
        return false;
    }
};
