// Leetcode 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Runtime: 6ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));

	node = head;
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}

	head = node;

	int t = count - n;

	if (t == 0)
	{
		node = node->next;
	}
	else
	{
		for (int i = 0; i < t; i++)
		{
			prev = head;
			head = head->next;
		}

		prev->next = head->next;
		free(head);
	}
	return node;
}

// 3ms参考解法
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *pointer = head;
    int topIter = 0;
	unsigned int stack[1000] = {0} ;
	while( pointer!= 0 ){
		stack[topIter++] = (unsigned int)pointer;
		pointer = pointer->next;
	}
	int iter = topIter - n;
    if( !iter ){
        free( (void*)stack[0]);
        head = (struct ListNode*)stack[1];
        return head;
    }
	pointer = (struct ListNode* )stack[iter-1];
	pointer->next = (struct ListNode* )stack[iter+1];
	free((void*)stack[iter]);
	return head;
}
