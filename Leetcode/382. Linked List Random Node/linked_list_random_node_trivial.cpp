// Leetcode 382. Linked List Random Node
// https://leetcode.com/problems/linked-list-random-node/
// Runtime: 40 ms
// Memory Usage: 16.4 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// not good for extremely large linked list
class Solution 
{
    ListNode *node = NULL;
    ListNode *headNode = NULL;
    int size = 0;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        this->node = head;
        this->headNode = head;
        
        ListNode *tmp = head;
        while (tmp)
        {
            size++;
            tmp = tmp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int randomPos = rand() % size;
        int c = 0;
        node = headNode;

        while (c < randomPos)
        {
            c++;
            node = node->next;
        }
        
        int ret = node->val;
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
