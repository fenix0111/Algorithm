// Leetcode 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
// Runtime: 23ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode *makeBST(int *v, int l, int m, int r)
{
	if (m < l || m > r)
		return NULL;

	int rl = m + 1;
	int rm = rl + (r - rl) / 2;

	int lr = m - 1;
	int lm = l + (lr - l) / 2;

	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = v[m];
	node->left = makeBST(v, l, lm, lr);
	node->right = makeBST(v, rl, rm, r);
	
	return node;
}

TreeNode* sortedListToBST(ListNode* head) 
{
	if (head == NULL)
	{
		return NULL;
	}

	TreeNode* h = (TreeNode*)malloc(sizeof(TreeNode));
	ListNode* pl = (ListNode*)malloc(sizeof(ListNode));
	pl = head;

	int size = 0;
	while (pl)
	{
		size++;
		pl = pl->next;
	}

	pl = head;
	int *tmp = (int*)malloc(sizeof(int) * size);
	int i = 0;
	while (pl)
	{
		tmp[i] = pl->val;
		pl = pl->next;
		i++;
	}

	int mid = size / 2;
	int r = size - 1;
	h = makeBST(tmp, 0, mid, r);
	return h;
}
};
