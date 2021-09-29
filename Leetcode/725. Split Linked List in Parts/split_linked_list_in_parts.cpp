// Leetcode 725. Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/
// time complexity: O(n)
// space complexity: O(n)

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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*> result;        
        int size = 0;
        ListNode* h = head;
        while (h)
        {
            h = h->next;
            size++;
        }

        int remain = size % k;
        int groupSize = size / k;
        h = head;
        while (h)
        {
            ListNode* newNode = new ListNode(h->val);
            result.push_back(newNode);
            int targetSize = groupSize - 1;
            if (remain > 0)
            {
                targetSize++;
                remain--;
            }

            while (h->next && targetSize > 0)
            {
                h = h->next;
                newNode->next = new ListNode(h->val);
                newNode = newNode->next;
                targetSize--;
            }

            newNode->next = nullptr;
            
            if (h == nullptr)
            {
                break;
            }

            h = h->next;
        }

        while (result.size() < k)
        {
            result.push_back(nullptr);
        }

        return result;
    }
};
