// Leatcode 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/
// Runtime: 38ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int CF = 0; // 1 if carry happened, 0 otherwise 
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = NULL;

	while (l1 || l2)
	{
		struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (l1 && l2)
		{
			int sum = l1->val + l2->val;

			if (CF)
			{
				sum++;
				CF = 0;
			}

			if (sum >= 10)
			{
				CF = 1;
				sum -= 10;
			}
			node->val = sum;
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1 == NULL && l2)
		{
			int sum = l2->val;
			if (CF)
			{
				sum++;
				CF = 0;
			}
			if (sum >= 10)
			{
				CF = 1;
				sum -= 10;
			}
			node->val = sum;
			l2 = l2->next;
		}
		else if (l1 && l2 == NULL)
		{
			int sum = l1->val;
			if (CF)
			{
				sum++;
				CF = 0;
			}
			if (sum >= 10)
			{
				CF = 1;
				sum -= 10;
			}
			node->val = sum;
			l1 = l1->next;
		}

		node->next = head;
		head = node;
	}

	if (CF)
	{
		struct ListNode *finalnode = (struct ListNode*)malloc(sizeof(struct ListNode));
		finalnode->val = 1;
		finalnode->next = head;
		head = finalnode;
	}

	// reverse linkedlist
	struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode *hed = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *nxt = (struct ListNode*)malloc(sizeof(struct ListNode));

	hed = NULL;
	cur = head;
	nxt = head->next;

	while (cur != NULL)
	{
		cur->next = hed;
		hed = cur;
		cur = nxt;
		if (nxt != NULL)
		{
			nxt = nxt->next;
		}

	}
	ret = hed;
	return ret;
}

// 22ms参考解法
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    int carry=0,buffer;
    ListPointer head,temp,last;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=0;
    head->next=NULL;
    last=head;
    while(l1!=NULL || l2!=NULL || carry)
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        buffer=carry;
        if(l1!=NULL) buffer += l1->val;
        if(l2!=NULL) buffer += l2->val;
        temp->val=buffer%10;
        carry=(int)buffer/10;
        last->next=temp;
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
        last=temp;
    }
    return head->next;
}
