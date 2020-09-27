// Leetcode 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// time complexity: O(length of linked list)
// space complexity: O(length of linked list)

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
class Solution 
{
public:
    ListNode* reverse(ListNode* node, ListNode* newHead, ListNode* newNext, int k, int n)
    {
        if (n > k)
            return NULL;
        
        if (node)
        {            
            // nextNode will be null if reached the end of the group, or reach the end of the linked list 
            ListNode* nextNode = reverse(node->next, newHead, newNext, k, n + 1);
            if (nextNode)
            {
                nextNode->next = node;
            }
            else
            {
                newHead->next = node;
                newNext->next = node->next;
            } 
                
            return node;
        }
        else
        {
            return NULL;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        
        // point to new head in reversed group
        ListNode* newHead = new ListNode(-1);  
        
        // point to next element of newHead, so that the tail of last reversed group can point to this node
        ListNode* newNext = new ListNode(-1);  

        ListNode* h = head;
        ListNode* ret = new ListNode(-1);
        
        while (h)
        {
            sz++;
            h = h->next;
        }
        
        h = head;
        
        while (sz - k >= 0)
        {
            ListNode* front = reverse(head, newHead, newNext, k, 1);
            if (!ret->next)
            {
                // result node, only touch once
                ret->next = newHead->next;
            }      
            
            // h point to the tail of last reversed group can point to this node
            h->next = newHead->next;
            h = front;

            front->next = newNext->next;
            head = newNext->next;
            
            sz -= k;
        }
        
        return ret->next;
    }
};
