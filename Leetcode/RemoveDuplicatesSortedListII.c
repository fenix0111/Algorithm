// Leetcode 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
// Runtime: 3ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // 
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    if (head == NULL)
		return head;

	struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *last = (struct ListNode*)malloc(sizeof(struct ListNode));

	p->next = head;
	last->next = head;
	cur = head;

	while (cur)
	{
		if (cur->next && cur->val == cur->next->val)
		{
			while (cur->next && cur->val == cur->next->val)
			{
				cur = cur->next;
			}

			if (last->next == head)
				head = cur->next;

			last->next = cur->next;
			cur = cur->next;
		}
		else
		{
			cur = cur->next;
			last = last->next;
		}
	}

	return head;
}
