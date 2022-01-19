// Leetcode 817. Linked List Components
// https://leetcode.com/problems/linked-list-components/submissions/
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
    int numComponents(ListNode* head, vector<int>& nums)
    {
        unordered_map<int, bool> numset;
        for (int num : nums)
        {
            numset[num] = true;
        }
        
        int components = 0;
        
        // count the visited value in nums array
        int visited = 0;
        
        // nums array contains previous node value
        bool prev = false;
        while (head && visited < nums.size())
        {
            int val = head->val;
            if (prev)
            {
                if (numset.count(val) && numset[val])
                {
                    numset[val] = false;
                    visited++;
                }
                else
                {
                    prev = false;
                }
            }
            else
            {
                if (numset.count(val) && numset[val])
                {
                    visited++;
                    components++;
                    prev = true;
                    numset[val] = false;
                }
            }
            
            head = head->next;
        }
        
        return components;
    }
};
