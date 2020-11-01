// Leetcode 1290. Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// time complexity: O(length of linked list)
// space complexity: O(1)

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
    int getDecimalValue(ListNode* head) 
    {
        int result = 0;
        while (head)
        {
            result = result << 1;
            result += head->val;
            
            head = head->next;
        }
        
        return result;
    }
};
