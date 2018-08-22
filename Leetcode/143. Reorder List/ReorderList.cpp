// Leetcode 143. Reorder List
// https://leetcode.com/problems/reorder-list/description/
// Runtime: 64ms (slow..)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // used deque
class Solution {
public:
    void reorderList(ListNode* head) {
        if (NULL == head || NULL == head->next || NULL == head->next->next) {
            return;
        }
        
        deque<ListNode*> q;
        
        ListNode *h = head;
        while (h) {
            q.push_back(h);
            h = h->next;
        }
        
        int size = q.size();
        
        ListNode *t = NULL;
        for (int i = size - 1; i > size / 2; i--) {
            h = q.front();
            t = q.back();
            
            q.pop_front();
            
            h->next = t;
            t->next = q.front();
            
            q.pop_back();
        }
        
        if (q.size() == 2) {
            // when linked list has even number of node
            h = q.front();
            t = q.back();
            h->next = t;
            t->next = NULL;
        } else if (q.size() == 1) {
            h = q.front();
            h->next = NULL;
        }
    }
};
